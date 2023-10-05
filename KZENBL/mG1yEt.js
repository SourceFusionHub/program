class Graph {
  constructor(vertices) {
    this.vertices = vertices;
    this.adjList = new Map();
    for (let i = 0; i < vertices; i++) {
      this.adjList.set(i, []);
    }
  }

  addEdge(u, v) {
    this.adjList.get(u).push(v);
  }

  topologicalSortUtil(v, visited, stack) {
    visited[v] = true;
    const neighbors = this.adjList.get(v);

    for (const neighbor of neighbors) {
      if (!visited[neighbor]) {
        this.topologicalSortUtil(neighbor, visited, stack);
      }
    }

    stack.push(v);
  }

  topologicalSort() {
    const visited = new Array(this.vertices).fill(false);
    const stack = [];

    for (let i = 0; i < this.vertices; i++) {
      if (!visited[i]) {
        this.topologicalSortUtil(i, visited, stack);
      }
    }

    return stack.reverse();
  }
}

const g = new Graph(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

const topologicalOrder = g.topologicalSort();
console.log("Topological Sort:", topologicalOrder);
