import Foundation

class Graph {
    var graph: [[Int]]
    var visited: [Bool]
    var colors: [Int]  // 0 and 1 represent two different colors for bipartite

    init(vertices: Int) {
        self.graph = Array(repeating: [Int](), count: vertices)
        self.visited = Array(repeating: false, count: vertices)
        self.colors = Array(repeating: -1, count: vertices)
    }

    func addEdge(_ u: Int, _ v: Int) {
        graph[u].append(v)
        graph[v].append(u)  // For an undirected graph
    }

    func isBipartite() -> Bool {
        for vertex in 0..<graph.count {
            if !visited[vertex] {
                if !dfs(vertex, 0) {
                    return false
                }
            }
        }
        return true
    }

    private func dfs(_ node: Int, _ color: Int) -> Bool {
        visited[node] = true
        colors[node] = color

        for neighbor in graph[node] {
            if !visited[neighbor] {
                if !dfs(neighbor, 1 - color) {
                    return false
                }
            } else if colors[neighbor] == color {
                return false
            }
        }

        return true
    }
}

// Example usage
let vertices = 4
let g = Graph(vertices: vertices)

g.addEdge(0, 1)
g.addEdge(0, 3)
g.addEdge(1, 2)
g.addEdge(2, 3)

if g.isBipartite() {
    print("The graph is bipartite.")
} else {
    print("The graph is not bipartite.")
}
