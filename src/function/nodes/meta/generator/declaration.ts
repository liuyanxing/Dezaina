import ts from "typescript";
import { getEnum } from "./enum";
import { getInterface } from "./interface";
import { DDeclaraction, DEnum, DInterface } from "./types";

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
  return declarations;
}
