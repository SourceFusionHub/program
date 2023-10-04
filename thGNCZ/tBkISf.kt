class Graph(val vertices: Int, val edges: List<Edge>) {
    data class Edge(val source: Int, val destination: Int, val weight: Int)

    fun bellmanFord(source: Int) {
        val distance = IntArray(vertices) { Int.MAX_VALUE }
        distance[source] = 0

        // Relax all edges vertices-1 times
        for (i in 1 until vertices) {
            for (edge in edges) {
                if (distance[edge.source] != Int.MAX_VALUE && distance[edge.source] + edge.weight < distance[edge.destination]) {
                    distance[edge.destination] = distance[edge.source] + edge.weight
                }
            }
        }

        // Check for negative-weight cycles
        for (edge in edges) {
            if (distance[edge.source] != Int.MAX_VALUE && distance[edge.source] + edge.weight < distance[edge.destination]) {
                println("Graph contains a negative-weight cycle.")
                return
            }
        }

        // Print the shortest distances from the source
        for (i in 0 until vertices) {
            println("Shortest distance from $source to $i is ${distance[i]}")
        }
    }
}

fun main() {
    val vertices = 5
    val edges = listOf(
        Graph.Edge(0, 1, 6),
        Graph.Edge(0, 2, 7),
        Graph.Edge(1, 2, 8),
        Graph.Edge(1, 3, -4),
        Graph.Edge(1, 4, 5),
        Graph.Edge(2, 3, 9),
        Graph.Edge(2, 4, -3),
        Graph.Edge(3, 1, 10),
        Graph.Edge(4, 0, 2),
        Graph.Edge(4, 3, 7)
    )

    val graph = Graph(vertices, edges)
    val source = 0
    graph.bellmanFord(source)
}
