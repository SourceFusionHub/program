class Graph {
  constructor(vertices) {
    this.vertices = vertices;
    this.adjList = new Map();
  }

  addVertex(v) {
    this.adjList.set(v, []);
  }

  addEdge(v, w) {
    this.adjList.get(v).push(w);
    this.adjList.get(w).push(v);
  }

  greedyMaxIndependentSet() {
    const independentSet = new Set();

    while (this.adjList.size > 0) {
      let maxDegreeVertex = null;
      let maxDegree = -1;

      for (const [vertex, neighbors] of this.adjList.entries()) {
        if (neighbors.length > maxDegree) {
          maxDegree = neighbors.length;
          maxDegreeVertex = vertex;
        }
      }

      if (maxDegreeVertex !== null) {
        independentSet.add(maxDegreeVertex);
        this.adjList.delete(maxDegreeVertex);

        // Remove neighbors
        for (const neighbor of this.adjList.values()) {
          const index = neighbor.indexOf(maxDegreeVertex);
          if (index !== -1) {
            neighbor.splice(index, 1);
          }
        }
      }
    }

    return Array.from(independentSet);
  }
}

// Example usage
const graph = new Graph(6);
graph.addVertex(0);
graph.addVertex(1);
graph.addVertex(2);
graph.addVertex(3);
graph.addVertex(4);
graph.addVertex(5);

graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 4);
graph.addEdge(3, 5);

const maxIndependentSet = graph.greedyMaxIndependentSet();
console.log("Maximum Independent Set:", maxIndependentSet);
