import ts, { Identifier, TypeOfExpression, TypeReference } from "typescript";
import fs, { readFileSync } from "fs";
import path from "path"
import { Graph } from "./utils/graph"
import Mustache from "mustache"

function concatDirFiles(dir: string) {
	let source: string = "";
	fs.readdirSync(dir).forEach(file => {
		const filePath = path.join(dir, file);
		source += fs.readFileSync(filePath).toString();
	});
	return source;
}

type Member = Array<{ name: string, type: string, isArray: boolean} | undefined>;

interface Interface {
	name: string
	members: Member
	mixins?: string[]
	isStruct: boolean
}

type Struct = Interface

interface Enum {
	name: string
	members: Array<string>
}

const interfaces: Array<Interface> = [];
const structs: Array<Struct> = [];
const enums: Array<Enum> = [];


function isStringKeyWord(node: ts.Node) {
	return node.kind === ts.SyntaxKind.StringKeyword;
}

function getNameText(name: ts.Identifier) {
	return name.escapedText as string;
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

function getInterfaceMembers(node: ts.InterfaceDeclaration) {
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
					throw new Error("illegal type");
				}
				typeRef = typeRef.typeArguments[0] as ts.TypeReferenceNode;
				typeName = getNameText(typeRef.typeName as ts.Identifier);
			}
			return { name, type: typeName, isArray};
		} else {
			throw Error("wrong member type");
		}
	})
}

function visitor(node: ts.Node) {
	if (ts.isEnumDeclaration(node)) {
		const enumNode = node as ts.EnumDeclaration;
		enums.push({
			name: getNameText(enumNode.name),
			members: enumNode.members.map(m => getNameText(m.name as ts.Identifier))
		});
	} else if (ts.isInterfaceDeclaration(node)) {
		const interfaceNode = node as ts.InterfaceDeclaration;
		const name = getNameText(interfaceNode.name);
		const members = getInterfaceMembers(interfaceNode);
		const mixins = getInterfaceMixins(interfaceNode);
		const isStruct = mixins.includes("Struct");
		if (!["Struct", "Message"].includes(name)) {
			interfaces.push({
				name,
				members,
				mixins: mixins.filter(m => m !== "Struct"),
				isStruct,
			})
		}
	}
	node.forEachChild(visitor);
}

function groupByExtends(interfaces: Interface[]) {
	const graph = new Graph();
	for (let interf of interfaces) {
		const from = interf.name;
		if (interf.mixins!.length === 0) {
			graph.addEdge(from, "");
			continue;
		}
		for (let mixin of interf.mixins!) {
			// console.log(mixin, from);
			graph.addEdge(mixin, from);
		}
	}
	return graph.groupByConnection();
}

function mixinInterfacByGroup(group: string[][]) {
	let interfaceMap: Map<string, Interface> = new Map();	
	for (let interf of interfaces) {
		interfaceMap.set(interf.name, interf);
	}
	group.reverse();
	let groupedInterface: Interface[] = [];
	for (let i of group) {
		const isStruct = i.some(name => interfaceMap.get(name)?.isStruct);
		const kiwiName = i.find(name => name.endsWith("_kiwi"));
		const name = kiwiName ? kiwiName.split("_kiwi")[0] : i[0];
		const item: Interface = {
			name,
			members: [],
			isStruct, 
		}
		for (let name of i) {
			const interf = interfaceMap.get(name);
			item.members.push(...(interf!.members))	
		}
		groupedInterface.push(item);
	}
	return groupedInterface;
}

function getSchemaData(interfaces: Interface[]) {
	const schemaData = {
		enums,
		structs: interfaces.filter((item) => item.isStruct),
		messages: interfaces.filter((item) => !item.isStruct),
	}
	return schemaData;
}

function main() {
	const source = concatDirFiles("./types");
	const sourceFile = ts.createSourceFile("type.ts", source, ts.ScriptTarget.ESNext);
	visitor(sourceFile);
	const grouped = groupByExtends(interfaces);
	const mixined =	mixinInterfacByGroup(grouped);
	const schemaData = getSchemaData(mixined);
	const template = readFileSync("./template/schema.mustache").toString();
	const reslut = Mustache.render(template, schemaData);
	fs.writeFileSync("desaina.kiwi", reslut);
}

main();