#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to implement the Bellman-Ford algorithm
int bellmanFord(int V, int E, int edges[][3], int s) {
    int dist[V + 1];  // Array to store the shortest distance from source
    dist[s] = 0;

    // Initialize the distances to all vertices as infinity
    for (int i = 1; i <= V; i++) {
        if (i != s) {
            dist[i] = INF;
        }
    }

    // Relax all edges |V-1| times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 0; // Negative cycle detected
        }
    }

    // Print the shortest distances from source
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    //printf("\n");

    return 1; // No negative cycle detected
}

int main() {
    int V, E;
    
    // Read the number of vertices and edges
    scanf("%d %d", &V, &E);

    int edges[E][3]; // Array to store edges (u, v, w)
    
    // Read the edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    int s;
    // Read the source vertex
    scanf("%d", &s);

    // Run the Bellman-Ford algorithm and check for negative cycle
    if (!bellmanFord(V, E, edges, s)) {
        printf("Negative Cycle Detected\n");
    }

    return 0;
}