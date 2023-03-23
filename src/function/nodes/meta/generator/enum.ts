import ts from "typescript";
import { DeclaractionType } from "./types";
import { getNameText } from "./util";

export function getEnum(node: ts.EnumDeclaration) {
  return {
    type: DeclaractionType.Enum,
    name: getNameText(node.name),
    members: node.members.map((m, index) => ({
      name: getNameText(m.name as ts.Identifier),
      index,
    })),
  };
}
