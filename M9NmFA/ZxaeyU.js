class Graph {
  constructor() {
    this.vertices = new Map();
  }

  addVertex(vertex) {
    if (!this.vertices.has(vertex)) {
      this.vertices.set(vertex, []);
    }
  }

  addEdge(vertex1, vertex2) {
    if (this.vertices.has(vertex1) && this.vertices.has(vertex2)) {
      this.vertices.get(vertex1).push(vertex2);
      this.vertices.get(vertex2).push(vertex1);
    }
  }

  biBFS(startNode, endNode) {
    if (!this.vertices.has(startNode) || !this.vertices.has(endNode)) {
      return null; // One or both nodes don't exist in the graph
    }

    const startQueue = [startNode];
    const endQueue = [endNode];
    const startVisited = new Set([startNode]);
    const endVisited = new Set([endNode]);

    while (startQueue.length > 0 && endQueue.length > 0) {
      const startFront = startQueue.shift();
      const endFront = endQueue.shift();

      for (const neighbor of this.vertices.get(startFront)) {
        if (!startVisited.has(neighbor)) {
          startQueue.push(neighbor);
          startVisited.add(neighbor);
        }

        if (endVisited.has(neighbor)) {
          return this.constructPath(startFront, neighbor, endFront);
        }
      }

      for (const neighbor of this.vertices.get(endFront)) {
        if (!endVisited.has(neighbor)) {
          endQueue.push(neighbor);
          endVisited.add(neighbor);
        }

        if (startVisited.has(neighbor)) {
          return this.constructPath(startFront, neighbor, endFront);
        }
      }
    }

    return null; // No path found
  }

  constructPath(startNode, middleNode, endNode) {
    const path = [];
    path.push(startNode);

    while (middleNode !== startNode) {
      path.push(middleNode);
      middleNode = this.findCommonNeighbor(middleNode, endNode);
    }

    path.push(endNode);
    return path;
  }

  findCommonNeighbor(node1, node2) {
    for (const neighbor of this.vertices.get(node1)) {
      if (this.vertices.get(node2).includes(neighbor)) {
        return neighbor;
      }
    }
    return null;
  }
}

// Example usage with user input:

const graph = new Graph();
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function promptForVertex() {
  rl.question('Enter a vertex (or type "done" to finish): ', (vertex) => {
    if (vertex.toLowerCase() === 'done') {
      promptForEdge();
    } else {
      graph.addVertex(vertex);
      promptForVertex();
    }
  });
}

function promptForEdge() {
  rl.question('Enter an edge (in the format "vertex1 vertex2" or type "done" to finish): ', (edge) => {
    if (edge.toLowerCase() === 'done') {
      rl.question('Enter the start node: ', (startNode) => {
        rl.question('Enter the end node: ', (endNode) => {
          const shortestPath = graph.biBFS(startNode, endNode);
          if (shortestPath) {
            console.log('Shortest Path:', shortestPath);
          } else {
            console.log('No path found.');
          }
          rl.close();
        });
      });
    } else {
      const [vertex1, vertex2] = edge.split(' ');
      graph.addEdge(vertex1, vertex2);
      promptForEdge();
    }
  });
}

console.log('Enter vertices and edges for the graph:');
promptForVertex();
