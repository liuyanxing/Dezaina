import fs from "fs";
import path from "path";
import ts from "typescript";
import { nodeIncludeDir, outDir } from "../const";
import { getCppHeaderTemplate, getScahemTemplate } from "../template";
import { getPathFromRelative } from "../utils/system";
import { genCppHeader } from "./cpp";
import { getDeclarations } from "./declaration";
import { genKiwiSchema } from "./scheme";
import toposort from "toposort";
import { DDeclaraction, DeclaractionType } from "./types";

function concatDirFiles(dir: string) {
  let source = "";
  fs.readdirSync(dir).forEach((file) => {
    const filePath = path.join(dir, file);
    source += fs.readFileSync(filePath).toString();
  });
  return source;
}

function moveOutFiles() {
  fs.cpSync(outDir, nodeIncludeDir, { recursive: true });
}

function sortDeclarationsByDepends(declars: DDeclaraction[]) {
  const edges: [string, string][] = [];
  declars.map((item) => {
    if (item.type ===  DeclaractionType.Interface) {
      if (item.depends.length) {
        item.depends.forEach((depend) => {
          edges.push([depend, item.name]);
        });
        return;
      }
    }
    edges.push(["", item.name]);
  });
  const interfaceNames = toposort(edges);
  declars.sort((a, b) => {
    return interfaceNames.indexOf(a.name) - interfaceNames.indexOf(b.name);
  });
}

function main() {
  const source = concatDirFiles(getPathFromRelative("../types"));
  const sourceFile = ts.createSourceFile(
    "type.ts",
    source,
    ts.ScriptTarget.ESNext
  );
  const declars = getDeclarations(sourceFile);
  sortDeclarationsByDepends(declars);
  const [filteredDeclars, mixinedInterfaces] = genKiwiSchema(declars, getScahemTemplate());
  genCppHeader(filteredDeclars, mixinedInterfaces, getCppHeaderTemplate());
  // genCppSource(declars, getCppSourceTemplate());
  moveOutFiles();
}

main();
