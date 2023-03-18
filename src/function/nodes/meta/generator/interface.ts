/* eslint-disable @typescript-eslint/no-non-null-assertion */

import ts from "typescript";
import { Member, DeclaractionType } from "./types";
import {
  getNameText,
  isStringKeyWord,
  getTypeAndDefaultValeFrom,
} from "./util";

function getInterfaceMembers(node: ts.InterfaceDeclaration): Member[] {
  return node.members
    .map((mem) => {
      const member = mem as ts.PropertySignature;
      const name = getNameText(member.name as ts.Identifier);
      const type = member.type!;
      let isArray = false;
      if (isStringKeyWord(type as ts.Node)) {
        return { name, type: "string", isArray };
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
        return { name, type: typeName, isArray };
      } else if (ts.isUnionTypeNode(type as ts.Node)) {
        const typeRef = type as ts.UnionTypeNode;
        const [typeName, defaultValue] = getTypeAndDefaultValeFrom(typeRef);
        return { name, type: typeName, defaultValue, isArray };
      }
      throw new Error("unkonw member");
    })
    .filter((member) => !!member);
}

function getInterfaceExtends(node: ts.InterfaceDeclaration): string[] {
  if (!node.heritageClauses) {
    return [];
  }
  if (node.heritageClauses?.length != 0) {
    if (node.heritageClauses?.length != 1) {
      throw new Error("extends error");
    }
    return node.heritageClauses[0].types.map(
      (type) => (type.expression as ts.Identifier).escapedText as string
    );
  }
  return [];
}

export function getInterface(node: ts.InterfaceDeclaration) {
  const interfaceNode = node as ts.InterfaceDeclaration;
  const name = getNameText(interfaceNode.name);
  const members = getInterfaceMembers(interfaceNode) as Member[];
  const mixins = getInterfaceExtends(interfaceNode);
  const isStruct = mixins.includes("Struct");
  if (!["Struct", "Message"].includes(name)) {
    return {
      name,
      type: DeclaractionType.Interface,
      members,
      mixins: mixins.filter((m) => m !== "Struct"),
      isStruct,
    };
  }
}
