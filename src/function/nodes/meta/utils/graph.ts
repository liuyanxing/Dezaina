class GNode {
	name: string;
	connections: Set<GNode> = new Set<GNode>();
	constructor(name: string) {
		this.name = name;
	}

	addConnection(node: GNode) {
		this.connections.add(node);
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
		fromNode.addConnection(toNode);
		toNode.addConnection(fromNode);
	}

	getOrCreate(name: string) {
		let node = this.nodes.get(name);
		if (!node) {
			node = new GNode(name);
			this.nodes.set(name, node);
		}
		return node;
	}

	visite(node: GNode, visited = new Set<GNode>()) {
		if (visited.has(node)) {
			return visited;
		}
		visited.add(node);
		const connectNodes = node.connections;
		for (let connectNode of connectNodes) {
			this.visite(connectNode, visited);
		}
		return visited;
	}

	groupByConnection() {
		let res: string[][] = [];
		let visited = new Set<string>();
		for (let [name, node] of this.nodes) {
			if (visited.has(name)) {
				continue;
			}
			let curNode: string[] = [];
			this.visite(node).forEach((node) => {
				const name = node.name;
				visited.add(name);
				curNode.push(name);
				return name;
			});
			
			res.push(curNode);
		}
		return res;
	}
}