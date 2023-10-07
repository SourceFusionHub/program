import java.util.*

class Graph(val vertices: Int) {
    val adjList = Array(vertices) { mutableListOf<Int>() }

    fun addEdge(u: Int, v: Int) {
        adjList[u].add(v)
        adjList[v].add(u)
    }

    fun isBipartite(): Boolean {
        val color = IntArray(vertices) { -1 }

        for (i in 0 until vertices) {
            if (color[i] == -1) {
                if (!bfs(i, color)) {
                    return false
                }
            }
        }

        return true
    }

    private fun bfs(startVertex: Int, color: IntArray): Boolean {
        val queue: Queue<Int> = LinkedList()
        queue.offer(startVertex)
        color[startVertex] = 0 // Assign the first color (0)

        while (queue.isNotEmpty()) {
            val currentVertex = queue.poll()
            val currentColor = color[currentVertex]

            for (neighbor in adjList[currentVertex]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - currentColor // Assign the opposite color
                    queue.offer(neighbor)
                } else if (color[neighbor] == currentColor) {
                    return false // The graph is not bipartite
                }
            }
        }

        return true
    }
}

fun main() {
    val graph = Graph(4)
    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 3)
    graph.addEdge(2, 3)

    val isBipartite = graph.isBipartite()
    if (isBipartite) {
        println("The graph is bipartite.")
    } else {
        println("The graph is not bipartite.")
    }
}
