/* eslint-disable @typescript-eslint/no-non-null-assertion */
import ts from "typescript";
import { getEnum } from "./enum";
import { getInterface } from "./interface";
import { DDeclaraction, DeclaractionType, DEnum, DInterface, Member } from "./types";

function setMemberType(declars: DDeclaraction[]) {
  const enumsNames = declars.filter((d) => d.type === DeclaractionType.Enum).map((d) => d.name);
  const interfaceNames = declars.filter((d) => d.type === DeclaractionType.Interface).map((d) => d.name);
  const interfaces = declars.filter((d) => d.type === DeclaractionType.Interface);
  interfaces.forEach((d) => {
    d.members.forEach((m: Member) => {
      if (interfaceNames.includes(m.type!)) {
        m.isComplexType = true;
      } else if (enumsNames.includes(m.type!)) {
        m.isEnum = true;
      } else if (m.type === "string") {
        m.isString = true;
      } else if (["number", "boolean", "float", "uint"].includes(m.type!)) {
        m.isBasicType = true;
      }
    });
  });
}

function setInterfaceDepends(declars: DDeclaraction[]) {
  const interfaces = declars.filter((d) => d.type === DeclaractionType.Interface);
  interfaces.forEach((item) => {
    if (item.type === DeclaractionType.Interface) {
      if (item.mixins.length) {
        item.mixins.forEach((mixin) => {
          item.depends.push(mixin);
        });
      }
      item.members.forEach((m) => {
        if (m.isComplexType) {
          item.depends.push(m.type!);
        }
      });
    }
  });
}

export function getDeclarations(node: ts.Node) {
  const declarations: DDeclaraction[] = [];
  function visit(node: ts.Node) {
    if (ts.isEnumDeclaration(node)) {
      const enumNode = node as ts.EnumDeclaration;
      const dEnum = getEnum(enumNode) as DEnum;
      declarations.push(dEnum);
    } else if (ts.isInterfaceDeclaration(node)) {
      const interfaceNode = node as ts.InterfaceDeclaration;
      const dInterface = getInterface(interfaceNode);
      if (dInterface) {
        declarations.push(dInterface as DInterface);
      }
    }
		node.forEachChild(visit);
  }
  visit(node);
  setMemberType(declarations);
  setInterfaceDepends(declarations);
  return declarations;
}
