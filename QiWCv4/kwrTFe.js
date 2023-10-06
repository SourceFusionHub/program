class PriorityQueue {
  constructor() {
    this.elements = [];
  }

  enqueue(element, priority) {
    this.elements.push({ element, priority });
    this.elements.sort((a, b) => a.priority - b.priority);
  }

  dequeue() {
    return this.elements.shift().element;
  }

  isEmpty() {
    return this.elements.length === 0;
  }
}

class Graph {
  constructor(vertices) {
    this.vertices = vertices;
    this.adjMatrix = new Array(vertices).fill(null).map(() => new Array(vertices).fill(0));
  }

  addEdge(from, to, weight) {
    this.adjMatrix[from][to] = weight;
    this.adjMatrix[to][from] = weight; // Assuming an undirected graph
  }

  aStarSearch(start, goal) {
    const openSet = new PriorityQueue();
    const cameFrom = {};
    const gScore = new Array(this.vertices).fill(Infinity);
    const fScore = new Array(this.vertices).fill(Infinity);

    gScore[start] = 0;
    fScore[start] = this.heuristic(start, goal);
    openSet.enqueue(start, fScore[start]);

    while (!openSet.isEmpty()) {
      const current = openSet.dequeue();

      if (current === goal) {
        return this.reconstructPath(cameFrom, current);
      }

      for (let neighbor = 0; neighbor < this.vertices; neighbor++) {
        if (this.adjMatrix[current][neighbor] > 0) {
          const tentativeGScore = gScore[current] + this.adjMatrix[current][neighbor];

          if (tentativeGScore < gScore[neighbor]) {
            cameFrom[neighbor] = current;
            gScore[neighbor] = tentativeGScore;
            fScore[neighbor] = gScore[neighbor] + this.heuristic(neighbor, goal);

            if (!openSet.elements.some((item) => item.element === neighbor)) {
              openSet.enqueue(neighbor, fScore[neighbor]);
            }
          }
        }
      }
    }

    return null; // No path found
  }

  heuristic(node, goal) {
    // Implement your heuristic function here (e.g., Euclidean distance)
    // This example assumes all heuristics are zero (Dijkstra's algorithm)
    return 0;
  }

  reconstructPath(cameFrom, current) {
    const path = [current];
    while (cameFrom[current] !== undefined) {
      current = cameFrom[current];
      path.unshift(current);
    }
    return path;
  }
}

// Example usage:
const graph = new Graph(5);
graph.addEdge(0, 1, 4);
graph.addEdge(0, 2, 2);
graph.addEdge(1, 3, 5);
graph.addEdge(1, 2, 1);
graph.addEdge(2, 3, 8);
graph.addEdge(2, 4, 10);
graph.addEdge(3, 4, 6);

const startNode = 0;
const goalNode = 4;
const shortestPath = graph.aStarSearch(startNode, goalNode);

if (shortestPath !== null) {
  console.log("Shortest path:", shortestPath);
} else {
  console.log("No path found.");
}
