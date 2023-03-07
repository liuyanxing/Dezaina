class GNode {
	name: string;
	pre: Set<GNode> = new Set<GNode>();
	next: Set<GNode> = new Set<GNode>();
	constructor(name: string) {
		this.name = name;
	}

	addNext(next: GNode) {
		this.next.add(next);
	}

	addPre(pre: GNode) {
		this.pre.add(pre);
	}
}

export class Graph {
	nodes: Map<string, GNode> = new Map<string, GNode>();
	addEdge(from: string, to: string) {
		if (to === "") {
			this.getOrCreate(from);
			return;
		}
		let fromNode = this.getOrCreate(from);
		let toNode = this.getOrCreate(to);
		fromNode.addNext(toNode);
		toNode.addPre(fromNode);
	}

	getOrCreate(name: string) {
		let node = this.nodes.get(name);
		if (!node) {
			node = new GNode(name);
			this.nodes.set(name, node);
		}
		return node;
	}

	visitePre(node: GNode, cb: (node: GNode) => void) {
		const preNodes = node.pre;
		for (let preNode of preNodes) {
			cb(preNode);
			this.visitePre(preNode, cb);
		}
	}

	visiteNext(node: GNode, cb: (node: GNode) => void) {
		const nextNodes = node.next;
		for (let nextNode of nextNodes) {
			cb(nextNode);
			this.visiteNext(nextNode, cb);
		}
	}

	groupByConnection() {
		let res: string[][] = [];
		let visited = new Set<string>();
		for (let [name, node] of this.nodes) {
			if (visited.has(name)) {
				continue;
			}
			visited.add(name);
			let curNodes = [name];
			this.visitePre(node, (vNode) => {
				if (visited.has(vNode.name)) {
					return;
				}
				curNodes.push(vNode.name);
				visited.add(vNode.name);
			});
			this.visiteNext(node, (vNode) => {
				if (visited.has(vNode.name)) {
					return;
				}
				curNodes.push(vNode.name);
				visited.add(vNode.name);
			});
			res.push(curNodes);
		}
		return res;
	}
}