class Graph {
  constructor() {
    this.vertices = new Map();
  }

  addVertex(vertex) {
    if (!this.vertices.has(vertex)) {
      this.vertices.set(vertex, new Map());
    }
  }

  addEdge(vertex1, vertex2, weight) {
    if (!this.vertices.has(vertex1) || !this.vertices.has(vertex2)) {
      throw new Error('Vertex not found in the graph');
    }

    this.vertices.get(vertex1).set(vertex2, weight);
  }

  dijkstra(startVertex) {
    const visited = new Set();
    const distances = new Map();
    const previous = new Map();

    // Initialize distances and previous nodes
    for (const vertex of this.vertices.keys()) {
      distances.set(vertex, Infinity);
      previous.set(vertex, null);
    }

    distances.set(startVertex, 0);

    while (visited.size < this.vertices.size) {
      const currentVertex = this.getMinDistanceVertex(distances, visited);

      visited.add(currentVertex);

      for (const [neighbor, weight] of this.vertices.get(currentVertex)) {
        const distance = distances.get(currentVertex) + weight;

        if (distance < distances.get(neighbor)) {
          distances.set(neighbor, distance);
          previous.set(neighbor, currentVertex);
        }
      }
    }

    return { distances, previous };
  }

  getMinDistanceVertex(distances, visited) {
    let minDistance = Infinity;
    let minVertex = null;

    for (const [vertex, distance] of distances.entries()) {
      if (!visited.has(vertex) && distance < minDistance) {
        minDistance = distance;
        minVertex = vertex;
      }
    }

    return minVertex;
  }

  shortestPath(startVertex, endVertex) {
    const { distances, previous } = this.dijkstra(startVertex);
    const path = [];
    let currentVertex = endVertex;

    while (currentVertex !== null) {
      path.unshift(currentVertex);
      currentVertex = previous.get(currentVertex);
    }

    return path;
  }
}

// Example usage:

const graph = new Graph();
graph.addVertex('A');
graph.addVertex('B');
graph.addVertex('C');
graph.addVertex('D');
graph.addVertex('E');

graph.addEdge('A', 'B', 4);
graph.addEdge('A', 'C', 2);
graph.addEdge('B', 'C', 5);
graph.addEdge('B', 'D', 10);
graph.addEdge('C', 'D', 3);
graph.addEdge('D', 'E', 7);
graph.addEdge('E', 'A', 3);

const startVertex = 'A';
const endVertex = 'D';

const shortestPath = graph.shortestPath(startVertex, endVertex);
console.log(`Shortest Path from ${startVertex} to ${endVertex}: ${shortestPath.join(' -> ')}`);
