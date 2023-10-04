class Graph {
  Map<String, List<String>> adjacencyList;

  Graph() {
    adjacencyList = {};
  }

  void addEdge(String node1, String node2) {
    // Adding edges -> undirected graph
    if (adjacencyList.containsKey(node1)) {
      adjacencyList[node1]!.add(node2);
    } else {
      adjacencyList[node1] = [node2];
    }

    if (adjacencyList.containsKey(node2)) {
      adjacencyList[node2]!.add(node1);
    } else {
      adjacencyList[node2] = [node1];
    }
  }

  List<String> shortestPath(String startNode, String endNode) {
    // Performing BFS -> the shortest path
    final visited = <String, bool>{};
    final queue = Queue<String>();
    final parent = <String, String>{};

    queue.add(startNode);
    visited[startNode] = true;

    while (queue.isNotEmpty) {
      final currentNode = queue.removeFirst();

      if (currentNode == endNode) {
        // Reconstructing -> the shortest path
        final path = <String>[];
        var current = endNode;

        while (current != startNode) {
          path.add(current);
          current = parent[current]!;
        }

        path.add(startNode);
        return path.reversed.toList();
      }

      for (final neighbor in adjacencyList[currentNode]!) {
        if (!visited.containsKey(neighbor) || !visited[neighbor]!) {
          visited[neighbor] = true;
          queue.add(neighbor);
          parent[neighbor] = currentNode;
        }
      }
    }

    // If no path exists, return an empty list
    return [];
  }
}

void main() {
  final graph = Graph();

  // Add edges to the graph
  graph.addEdge("A", "B");
  graph.addEdge("A", "C");
  graph.addEdge("B", "D");
  graph.addEdge("C", "E");
  graph.addEdge("D", "E");
  graph.addEdge("D", "F");
  graph.addEdge("E", "F");

  final startNode = "A";
  final endNode = "F";

  final shortestPath = graph.shortestPath(startNode, endNode);

  if (shortestPath.isNotEmpty) {
    print("Shortest path from $startNode to $endNode: ${shortestPath.join(" -> ")}");
  } else {
    print("No path exists from $startNode to $endNode.");
  }
}
