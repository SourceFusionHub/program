#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Assumes the graph to be represented by an adjacency list
class Graph {
private:
    int V;
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges with source and destination separated by space: " << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS starting from node " << startNode << ": ";
    graph.BFS(startNode);

    return 0;
}
