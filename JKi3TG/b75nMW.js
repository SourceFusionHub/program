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
    this.adjList.get(v).push(u);
  }

  // Greedy algorithm to find an approximate minimum vertex cover
  findMinVertexCover() {
    const cover = new Set();

    while (this.adjList.size > 0) {
      let maxDegree = -1;
      let maxVertex = -1;

      // Find the vertex with the highest degree
      for (const [vertex, neighbors] of this.adjList.entries()) {
        if (neighbors.length > maxDegree) {
          maxDegree = neighbors.length;
          maxVertex = vertex;
        }
      }

      // Add the vertex to the cover and remove it and its neighbors from the graph
      cover.add(maxVertex);
      this.adjList.delete(maxVertex);
      for (const neighbor of this.adjList.values()) {
        const index = neighbor.indexOf(maxVertex);
        if (index !== -1) {
          neighbor.splice(index, 1);
        }
      }
    }

    return Array.from(cover);
  }
}

// Example usage:
const graph = new Graph(5);
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 4);

const minVertexCover = graph.findMinVertexCover();
console.log("Approximate Minimum Vertex Cover:", minVertexCover);
