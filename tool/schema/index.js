#!/usr/bin/env node

const fs = require("fs");
const kiwiSchema = require("kiwi-schema");
const jszip = require("jszip");
const pako = require("pako");

async function main() {
	const buffer = fs.readFileSync("./figs/rect.fig").buffer;
	const file = await jszip.loadAsync(buffer);
	const fig = await file.file("canvas.fig").async("uint8array");
	let cursor = 0;
	cursor += 12;
	const schemaLength = new DataView(fig.buffer).getUint32(cursor, true);
	cursor += 4;
	const schemaZip = fig.slice(cursor, cursor + schemaLength);
	const schemaBuffer = pako.inflateRaw(schemaZip);
	const schema = kiwiSchema.decodeBinarySchema(schemaBuffer);
	let cppCode = kiwiSchema.compileSchemaCPP(schema);
	cppCode = cppCode.replace('#include "kiwi.h"', '');
	cppCode = `#pragma once

#include "vendor/figma/kiwi.h"

namespace message {
	${cppCode}
}
	`

	const messagePath = "./dea/schema/message.h";
	fs.writeFileSync(messagePath, cppCode);
}

main();