class Graph {
  constructor(vertices) {
    this.vertices = vertices;
    this.adjacencyList = new Map();
  }

  addEdge(u, v, weight) {
    if (!this.adjacencyList.has(u)) {
      this.adjacencyList.set(u, []);
    }
    this.adjacencyList.get(u).push({ v, weight });
  }

  topologicalSortUtil(v, visited, stack) {
    visited[v] = true;
    if (this.adjacencyList.has(v)) {
      for (const neighbor of this.adjacencyList.get(v)) {
        if (!visited[neighbor.v]) {
          this.topologicalSortUtil(neighbor.v, visited, stack);
        }
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

  longestPath(start) {
    const stack = this.topologicalSort();
    const dist = new Array(this.vertices).fill(-Infinity);
    dist[start] = 0;

    while (stack.length > 0) {
      const u = stack.pop();
      if (dist[u] !== -Infinity) {
        if (this.adjacencyList.has(u)) {
          for (const neighbor of this.adjacencyList.get(u)) {
            if (dist[u] + neighbor.weight > dist[neighbor.v]) {
              dist[neighbor.v] = dist[u] + neighbor.weight;
            }
          }
        }
      }
    }

    return dist;
  }
}

// Example usage:
const graph = new Graph(6);
graph.addEdge(0, 1, 5);
graph.addEdge(0, 2, 3);
graph.addEdge(1, 3, 6);
graph.addEdge(1, 2, 2);
graph.addEdge(2, 4, 4);
graph.addEdge(2, 5, 2);
graph.addEdge(2, 3, 7);
graph.addEdge(3, 5, 1);
graph.addEdge(3, 4, -1);
graph.addEdge(4, 5, -2);

const startVertex = 1;
const dist = graph.longestPath(startVertex);

console.log("Longest paths from vertex " + startVertex + ":");
for (let i = 0; i < graph.vertices; i++) {
  console.log(`Vertex ${i}: ${dist[i]}`);
}
