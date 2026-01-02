#include <iostream>
#include <climits>
#define MAX_ROUTERS 100
using namespace std;
int minDistance(int dist[], bool sptSet[], int numRouters) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < numRouters; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int numRouters) {
    for (int i = 0; i < numRouters; i++)
        cout << i << " " << dist[i] << endl;
}

void dijkstra(int graph[MAX_ROUTERS][MAX_ROUTERS], int src, int numRouters) {
    int dist[MAX_ROUTERS];
    bool sptSet[MAX_ROUTERS];

    for (int i = 0; i < numRouters; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < numRouters - 1; count++) {
        int u = minDistance(dist, sptSet, numRouters);
        sptSet[u] = true;

        for (int v = 0; v < numRouters; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, numRouters);
}
Footer
int main() {
    int numRouters, numLinks;
    cin >> numRouters >> numLinks;

    int graph[MAX_ROUTERS][MAX_ROUTERS] = {0};

    for (int i = 0; i < numLinks; i++) {
        int router1, router2, weight;
        cin >> router1 >> router2 >> weight;
        graph[router1][router2] = weight;
        graph[router2][router1] = weight; // undirected graph
    }

    int source, destination;
    cin >> source >> destination;

    dijkstra(graph, source, numRouters);

    return 0;
}