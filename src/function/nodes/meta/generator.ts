import ts, { Identifier, TypeReference } from "typescript";
import fs from "fs";
import path from "path"
import toposort from "toposort"
import { group } from "console";

function concatDirFiles(dir: string) {
	let source: string = "";
	fs.readdirSync(dir).forEach(file => {
		const filePath = path.join(dir, file);
		source += fs.readFileSync(filePath).toString();
	});
	return source;
}

interface Interface {
	name: string
	members: Array<{ name: string, type: string, isArray: boolean} | undefined>
	mixins: string[]
	isStruct: boolean
}

type Struct = Interface

interface Enum {
	members: Array<string>
}

const interfaces: Array<Interface> = [];
const structs: Array<Struct> = [];
const enums: Array<Enum> = [];

const schemaData = {
	interfaces,
	structs,
	enums,
}

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
		const type = member.type;
		let isArray = false;
		if (isStringKeyWord(type as ts.Node)) {
			return { name, type: "string", isArray};
		}
		if (ts.isTypeReferenceNode(type as ts.Node)) {
			let typeRef = type as ts.TypeReferenceNode;	
			let typeName = getNameText(typeRef.typeName as ts.Identifier);
			if (typeName === "Array") {
				isArray = true;
				if (typeRef.typeArguments?.length !== 1) {
					console.log(typeRef.typeArguments);
					throw new Error("illegal type");
				}
				typeRef = typeRef.typeArguments[0] as ts.TypeReferenceNode;
				typeName = getNameText(typeRef.typeName as ts.Identifier);
			}
			return { name, type: typeName, isArray};
		} else {
			// throw new Error("illegal type");
		}
	})
}

function visitor(node: ts.Node) {
	if (ts.isInterfaceDeclaration(node)) {
		const interfaceNode = node as ts.InterfaceDeclaration;
		const name = getNameText(interfaceNode.name);
		console.log(name);
		const members = getInterfaceMembers(interfaceNode);
		const mixins = getInterfaceMixins(interfaceNode);
		const isStruct = mixins.includes("Struct");
		if (!["Struct", "Message"].includes(name)) {
			interfaces.push({
				name,
				members,
				mixins,
				isStruct,
			})
		}
	}
	node.forEachChild(visitor);
}

function sortInterface(interfaces: Array<Interface>) {
	const edges: [string, string | undefined][] = [];
	for (let interf of interfaces) {
		const from = interf.name;
		if (interf.mixins.length === 0) {
			edges.push([from, undefined]);
			continue;
		}
		for (let mixin of interf.mixins) {
			edges.push([mixin, from]);
		}
	}
	const res = toposort(edges).filter(c => !!c && c !== "Struct");
	return res;
}

function groupByExtends(interfaceNames: string[]) {
	const typeMaps: Record<string, Interface> = {};
	for (let interf of interfaces) {
		typeMaps[interf.name] = interf;
	}
	const groups: Interface[][] = [];
	for (let interfaceName of interfaceNames) {
		const extendNames = typeMaps[interfaceName].mixins;
		if (!extendNames.length) {
			groups.push([typeMaps[interfaceName]]);
			continue;
		}
		for (let group of groups) {
			if (extendNames.some(extName => {
				return group.some(interf => interf.name === extName);
			})) {
				group.push(typeMaps[interfaceName]);
				break;
			}
		}
	}
	return groups;
}

function main() {
	const source = concatDirFiles("./types");
	const sourceFile = ts.createSourceFile("type.ts", source, ts.ScriptTarget.ESNext);
	visitor(sourceFile);
	sortInterface(interfaces);
}

main();