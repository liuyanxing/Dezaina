import fs from "fs";
import path from "path";

export function getCppHeaderTemplate() {
	return fs.readFileSync(path.join(__dirname, "./cpp.header.mustache")).toString();
}

export function getCppSourceTemplate() {
	return fs.readFileSync(path.join(__dirname, "./cpp.source.mustache")).toString();
}

export function getScahemTemplate() {
	return fs.readFileSync(path.join(__dirname, "./schema.mustache")).toString();
}