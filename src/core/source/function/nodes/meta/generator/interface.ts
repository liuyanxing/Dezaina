/* eslint-disable @typescript-eslint/no-non-null-assertion */

import ts from "typescript";
import { Member, DeclaractionType, DInterface } from "./types";
import {
  getNameText,
  isStringKeyWord,
  getTypeAndDefaultValeFrom,
  remvoeMark,
} from "./util";

function getInterfaceMembers(node: ts.InterfaceDeclaration): Member[] {
  return node.members
    .map((mem) => {
      const member = mem as ts.PropertySignature;
      const name = getNameText(member.name as ts.Identifier);
      if (!member.type) {
        throw new Error("member type error");
      }
      const type = member.type!;
      let isArray = false;
      let res: Member = { name: remvoeMark(name) };
      if (isStringKeyWord(type as ts.Node)) {
        res =  { ...res, type: "string", isArray };
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
        res = { ...res, type: typeName, isArray };
      } else if (ts.isUnionTypeNode(type as ts.Node)) {
        const typeRef = type as ts.UnionTypeNode;
        const [typeName, defaultValue] = getTypeAndDefaultValeFrom(typeRef);
        return { name, type: typeName, defaultValue, isArray };
      } else if (ts.isLiteralTypeNode(type as ts.Node)) {
        if (name.endsWith("_function")) {
          const literalType = member.type as ts.LiteralTypeNode;
          const stringLiteral = literalType.literal as ts.StringLiteral;
          res = {
            ...res,
            type: "function",
            defaultValue: stringLiteral.text,
            isFunction: true,
          };
        }
      } else {
        throw new Error("unkonw member");
      }
      if (res.type) {
        if (res.type.includes("_pointer")) {
          res.isPointer = true;
        }
        res.type = remvoeMark(res.type);
      }
      return res;
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
      depends: [],
      isStruct,
    } as DInterface;
  }
}
