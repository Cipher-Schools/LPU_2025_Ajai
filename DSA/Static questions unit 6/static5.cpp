#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX
void floydWarshall(int dist[][5], int N) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void printSolution(int dist[][5], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int dist[5][5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = (dist[u][v] < w) ? dist[u][v] : w;
    }
    floydWarshall(dist, N);
    printSolution(dist, N);
    return 0;
}