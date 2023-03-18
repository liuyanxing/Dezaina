import fs from "fs";
import path from "path";

export function getCppTemplate() {
	return fs.readFileSync(path.join(__dirname, "./cpp.mustache")).toString();
}

export function getScahemTemplate() {
	return fs.readFileSync(path.join(__dirname, "./schema.mustache")).toString();
}