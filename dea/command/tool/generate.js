import { CmdConfig } from './cmd_config.js';
import mustache from './mustache.js';
import fs from 'fs';

const data = {
	cmds: CmdConfig
}

let template = fs.readFileSync('./cmd.mustache').toString();
let output = mustache.render(template, data);
fs.writeFileSync('../cmds.generated.h', output);

template = fs.readFileSync('./build_cmds.mustache').toString();
output = mustache.render(template, data);
fs.writeFileSync('../build_cmds.generated.cpp', output);