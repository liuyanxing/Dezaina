import ts, { Identifier } from "typescript";

type DefalutValue = number | string | boolean;

export function isStringKeyWord(node: ts.Node) {
  return node.kind === ts.SyntaxKind.StringKeyword;
}

export function isTrueKeyWord(node: ts.Node) {
  return node.kind === ts.SyntaxKind.TrueKeyword;
}

export function isFalseKeyWord(node: ts.Node) {
  return node.kind === ts.SyntaxKind.FalseKeyword;
}

export function getNameText(name: ts.Identifier) {
  return name.escapedText as string;
}

export function getTypeAndDefaultValeFrom(
  node: ts.UnionTypeNode
): [string, DefalutValue] {
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
