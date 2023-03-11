import ts, { Identifier } from "typescript";
import fs, { readFileSync } from "fs";
import { promisify } from "util";
import { exec } from "child_process";
import path from "path"
import { Graph } from "./utils/graph"
import Mustache from "mustache"

const execSync = promisify(exec);

function concatDirFiles(dir: string) {
	let source: string = "";
	fs.readdirSync(dir).forEach(file => {
		const filePath = path.join(dir, file);
		source += fs.readFileSync(filePath).toString();
	});
	return source;
}

type DefalutValue = number | string | boolean;
interface Member {
	name: string,
	type: string,
	isArray: boolean,
	defaultValue?: DefalutValue,
	index?: number
}

enum DeclaractionType {
	Interface,
	Enum,
}

interface DInterface {
	name: string
	type: DeclaractionType.Interface
	members: Member[]
	mixins?: string[]
	isStruct: boolean
}

interface DEnum {
	type: DeclaractionType.Enum
	name: string
	members: Array<{name: string, index: number}>
}

type Declaraction = DInterface | DEnum;

function isStringKeyWord(node: ts.Node) {
	return node.kind === ts.SyntaxKind.StringKeyword;
}

function isTrueKeyWord(node: ts.Node) {
	return node.kind === ts.SyntaxKind.TrueKeyword;
}

function isFalseKeyWord(node: ts.Node) {
	return node.kind === ts.SyntaxKind.FalseKeyword;
}

function getNameText(name: ts.Identifier) {
	return name.escapedText as string;
}

function getTypeAndDefaultValeFrom(node: ts.UnionTypeNode): [string, DefalutValue] {
	const typeNode = node.types[0] as ts.TypeReferenceNode;
	const valueNode = node.types[1] as ts.LiteralTypeNode;
	let value: DefalutValue = 0;
	const literal = valueNode.literal;
	if (isTrueKeyWord(literal)) {
		value = true;
	} else if (isFalseKeyWord(literal)) {
		value = false;
	} else {
		value = (valueNode.literal as ts.StringLiteral).text;
	}
	return [getNameText(typeNode.typeName as Identifier), value];
}

function getInterfaceMixins(node: ts.InterfaceDeclaration): string[] {
	if (!node.heritageClauses) {
		return [];
	}
	if (node.heritageClauses?.length != 0) {
		if (node.heritageClauses?.length != 1) {
			throw new Error("extends error");
		}
		return node.heritageClauses[0].types.map(type => (type.expression as ts.Identifier).escapedText as string);
	}
	return [];
}

function getInterfaceMembers(node: ts.InterfaceDeclaration): (Member | undefined)[] {
	return node.members.map((mem) => {
		let member = mem as ts.PropertySignature;
		const name = getNameText(member.name as ts.Identifier); 
		const type = member.type!;
		let isArray = false;
		if (isStringKeyWord(type as ts.Node)) {
			return { name, type: "string", isArray};
		} else if (ts.isTypeReferenceNode(type as ts.Node)) {
			let typeRef = type as ts.TypeReferenceNode;
			let typeName = getNameText(typeRef.typeName as ts.Identifier);
			if (["Array", "ReadonlyArray"].includes(typeName)) {
				isArray = true;
				if (typeRef.typeArguments?.length !== 1) {
					throw new Error("typeArguments error");
					
				}
				typeRef = typeRef.typeArguments[0] as ts.TypeReferenceNode;
				typeName = getNameText(typeRef.typeName as ts.Identifier);
			}
			return { name, type: typeName, isArray};
		} else if (ts.isUnionTypeNode(type as ts.Node)) {
			let typeRef = type as ts.UnionTypeNode;
			const [typeName, defaultValue] = getTypeAndDefaultValeFrom(typeRef);
			return { name, type: typeName, defaultValue, isArray};
		}
	})
}

function getDeclarations(node: ts.Node) {
	let declarations: Declaraction[] = []; 
	function visit(node: ts.Node) {
		if (ts.isEnumDeclaration(node)) {
			const enumNode = node as ts.EnumDeclaration;
			declarations.push({
				type: DeclaractionType.Enum,
				name: getNameText(enumNode.name),
				members: enumNode.members.map((m, index) => ({
					name: getNameText(m.name as ts.Identifier),
					index,
				}))
			});
		} else if (ts.isInterfaceDeclaration(node)) {
			const interfaceNode = node as ts.InterfaceDeclaration;
			const name = getNameText(interfaceNode.name);
			const members = getInterfaceMembers(interfaceNode) as Member[];
			const mixins = getInterfaceMixins(interfaceNode);
			const isStruct = mixins.includes("Struct");
			if (!["Struct", "Message"].includes(name)) {
				declarations.push({
					name,
					type: DeclaractionType.Interface,
					members,
					mixins: mixins.filter(m => m !== "Struct"),
					isStruct,
				})
			}
		}
		node.forEachChild(visit);
	}
	visit(node);
	return declarations;
}

function groupByExtends(interfaces: DInterface[]) {
	const graph = new Graph();
	for (let interf of interfaces) {
		const from = interf.name;
		if (interf.mixins!.length === 0) {
			graph.addEdge(from, "");
			continue;
		}
		for (let mixin of interf.mixins!) {
			graph.addEdge(mixin, from);
		}
	}
	return graph.groupByConnection();
}

function mixinInterfacByGroup(group: string[][], interfaces: DInterface[]) {
	let interfaceMap: Map<string, DInterface> = new Map();	
	for (let interf of interfaces) {
		interfaceMap.set(interf.name, interf);
	}
	group.reverse();
	let groupedInterface: DInterface[] = [];
	for (let i of group) {
		const isStruct = i.some(name => interfaceMap.get(name)?.isStruct);
		const kiwiName = i.find(name => name.endsWith("_kiwi"));
		const name = kiwiName ? kiwiName.split("_kiwi")[0] : i[0];
		const item: DInterface = {
			name,
			type: DeclaractionType.Interface,
			members: [],
			isStruct, 
		}
		for (let name of i) {
			const interf = interfaceMap.get(name);
			const members = interf!.members as Member[];
			item.members.push(...members)	
		}
		item.members = item.members.map((member, index) => ({ ...member, index: index + 1 })) as Member[];
		groupedInterface.push(item);
	}
	return groupedInterface;
}

function getSchemaData(interfaces: DInterface[], enums: DEnum[]) {
	const schemaData = {
		enums,
		structs: interfaces.filter((item) => item.isStruct),
		messages: interfaces.filter((item) => !item.isStruct),
	}
	return schemaData;
}

function getPathFromRelative(p: string) {
	return path.join(__dirname, p);	
}

function genKiwiSchema(declars: Declaraction[]) {
	const interfaces = declars.filter(dInterface => dInterface.type === DeclaractionType.Interface) as DInterface[];
	const enums = declars.filter(dInterface => dInterface.type === DeclaractionType.Enum) as DEnum[];
	const grouped = groupByExtends(interfaces);
	const mixined =	mixinInterfacByGroup(grouped, interfaces);
	const schemaData = getSchemaData(mixined, enums);
	const template = readFileSync(getPathFromRelative("./template/schema.mustache")).toString();
	const reslut = Mustache.render(template, schemaData);
	fs.writeFileSync(getPathFromRelative("desaina.kiwi"), reslut);
	execSync("kiwic --schema desaina.kiwi --cpp desaina_kiwi.h", { cwd: __dirname });
}


function genCppFils(declars: Declaraction[]) {
	const interfaces = declars.filter(dInterface => dInterface.type === DeclaractionType.Interface) as DInterface[];	
	const structs = interfaces.filter((item) => item.isStruct);
	const classes = interfaces.filter((item) => !item.isStruct);
	const enums = declars.filter(dInterface => dInterface.type === DeclaractionType.Enum) as DEnum[];
	const data = {
		classes,
		structs,
		enums,
	}
	const reslut = Mustache.render(readFileSync(getPathFromRelative("./template/cpp.mustache")).toString(), data);
	fs.writeFileSync(getPathFromRelative("desaina.h"), reslut);
}

function main() {
	const source = concatDirFiles(getPathFromRelative("./types"));
	const sourceFile = ts.createSourceFile("type.ts", source, ts.ScriptTarget.ESNext);
	const declars = getDeclarations(sourceFile);
	genKiwiSchema(declars);
	genCppFils(declars);
}

main();