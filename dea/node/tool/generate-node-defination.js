import fs, { promises as fsPromise } from 'fs'
import {
	enums,
	structs,
	baseMixins,
	nodeMixins,
	nodeBase,
	customType,
} from './definiations/index.js'
import mustache from './mustache/mustache.js'

async function writeFileSync(path, data) {
  let fileHandle;

  try {
    fileHandle = await fsPromise.open(path, 'w');
    await fileHandle.writeFile(data);
  } catch (err) {
    console.error('写入文件时出错:', err);
  } finally {
    if (fileHandle) {
      await fileHandle.close();
    }
  }
}

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

function procNodeExtends(o) {
	o.nodedExtends = [o.name, ...(o.nodedExtends || [])];
	if (o.nodedExtends) {
		o.inherits = ': ' + o.nodedExtends.map(e => 'public ' + e).join(', ');
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

data.structs.forEach(o => { procExtends(o); procChangeType(o); procClassGetterAndSetter(o); });
data.classes.forEach(o => { procExtends(o); procClassGetterAndSetter(o); });

let template = fs.readFileSync('./node_base.mustache').toString();
let output = mustache.render(template, data);
await writeFileSync('../node_base.generated.h', output);

nodeBase.forEach(o => { procNodeExtends(o); });
template = fs.readFileSync('./type.mustache').toString();
output = mustache.render(template, { nodes: nodeBase });
await writeFileSync('../type.generated.h', output);

template = fs.readFileSync('./node.mustache').toString();
output = mustache.render(template, { nodes: nodeBase });
await writeFileSync('../node.generated.h', output);
