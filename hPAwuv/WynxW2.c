#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int graph[MAX][MAX]; // Adjacency matrix to represent the graph
int visited[MAX];    // Array to track visited vertices
int disc[MAX];       // Discovery time of vertices
int low[MAX];        // Low value of vertices
int parent[MAX];     // Parent of vertices
int isArticulationPoint[MAX]; // To store whether a vertex is an articulation point

int V, E; // Number of vertices and edges

int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(int u, int time) {
    int children = 0;
    visited[u] = 1;
    disc[u] = time;
    low[u] = time;
    time++;

    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, time);

                low[u] = min(low[u], low[v]);

                if (low[v] >= disc[u]) {
                    isArticulationPoint[u] = 1;
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    if (parent[u] == -1 && children >= 2) {
        isArticulationPoint[u] = 1;
    }
}

void findArticulationPoints() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        parent[i] = -1;
        isArticulationPoint[i] = 0;
    }

    int time = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, time);
        }
    }

    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++) {
        if (isArticulationPoint[i]) {
            printf("%d\n", i);
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter the edges (in the format 'u v'):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    findArticulationPoints();

    return 0;
}
