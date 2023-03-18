import fs from "fs";
import path from "path";
import ts from "typescript";
import { getPathFromRelative } from "../utils/system";
import { genCpp } from "./cpp";
import { getDeclarations } from "./declaration";
import { genKiwiSchema } from "./scheme";

function concatDirFiles(dir: string) {
  let source = "";
  fs.readdirSync(dir).forEach((file) => {
    const filePath = path.join(dir, file);
    source += fs.readFileSync(filePath).toString();
  });
  return source;
}

function main() {
  const source = concatDirFiles(getPathFromRelative("../types"));
  const sourceFile = ts.createSourceFile(
    "type.ts",
    source,
    ts.ScriptTarget.ESNext
  );
  const declars = getDeclarations(sourceFile);
  genKiwiSchema(declars);
  genCpp(declars);
}

main();
