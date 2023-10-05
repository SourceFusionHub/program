class Graph {
    constructor(vertices) {
        this.vertices = vertices;
        this.graph = new Array(vertices);
        for (let i = 0; i < vertices; i++) {
            this.graph[i] = [];
        }
    }

    addEdge(u, v) {
        this.graph[u].push(v);
    }

    isHamiltonianCycleUtil(path, visited) {
        const v = path[path.length - 1];

        // If all vertices are included in the path, check if the last vertex connects back to the starting vertex.
        if (path.length === this.vertices) {
            if (this.graph[v].includes(path[0])) {
                return true;
            }
            return false;
        }

        for (let i = 0; i < this.graph[v].length; i++) {
            const next = this.graph[v][i];
            if (!visited[next]) {
                visited[next] = true;
                path.push(next);

                if (this.isHamiltonianCycleUtil(path, visited)) {
                    return true;
                }

                visited[next] = false;
                path.pop();
            }
        }

        return false;
    }

    hasHamiltonianCycle() {
        const visited = new Array(this.vertices).fill(false);
        const path = [0]; // Start from vertex 0

        if (this.isHamiltonianCycleUtil(path, visited)) {
            return true;
        }

        return false;
    }
}

// Example usage:

const g = new Graph(5);
g.addEdge(0, 1);
g.addEdge(1, 2);
g.addEdge(2, 3);
g.addEdge(3, 4);
g.addEdge(4, 0);

if (g.hasHamiltonianCycle()) {
    console.log("The graph contains a Hamiltonian cycle.");
} else {
    console.log("The graph does not contain a Hamiltonian cycle.");
}
