import fs from 'fs'
import {
	enums,
	structs,
	baseMixins,
	nodeMixins,
	nodeBase,
	customType,
} from './definiations/index.js'
import mustache from './mustache/mustache.js'

let data = {
	enums,
	structs,
	classes: [...baseMixins, ...nodeMixins, ...nodeBase],
	customType,
}

function procExtends(o) {
	if (o.extends) {
		o.inherits = ': ' + o.extends.map(e => 'public ' + e).join(', ');
		return;
	}
	o.inherits = null;
}

function procChangeType(o) {
	if (!o.changeType) {
		o.changeType = o.name;
	}	
}

data.structs.forEach(o => { procExtends(o); procChangeType(o); });
data.classes.forEach(o => { procExtends(o); });

let template = fs.readFileSync('./node.mustache').toString();
let output = mustache.render(template, data);
fs.writeFileSync('../node-base/node.generated.h', output);

