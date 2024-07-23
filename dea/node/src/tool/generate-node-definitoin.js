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

function procClassGetterAndSetter(o) {
	o.members.forEach(m => {
		m.getterName = 'get' + m.name[0].toUpperCase() + m.name.slice(1);
		m.setterName = 'set' + m.name[0].toUpperCase() + m.name.slice(1);
	});	
}

data.structs.forEach(o => { procExtends(o); procChangeType(o); });
data.classes.forEach(o => { procExtends(o); procClassGetterAndSetter(o); });

let template = fs.readFileSync('./node.mustache').toString();
let output = mustache.render(template, data);
fs.writeFileSync('../node-base/node.generated.h', output);

template = fs.readFileSync('./type.mustache').toString();
output = mustache.render(template, { nodes: nodeBase });
fs.writeFileSync('../node-base/type.generated.h', output);

