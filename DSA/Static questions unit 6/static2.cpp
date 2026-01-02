#include <iostream>
#include <vector>
using namespace std;
const int MAX_VERTICES = 100;
struct Graph {
    vector<int> visited;
    vector<vector<int>> adj;

    Graph(int n) {
        visited.assign(n, 0);
        adj.assign(n, vector<int>(n, 0));
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
    }

    void DFS(int v) {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < adj.size(); i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    Graph g(n);

    int v, w;
    for (int i = 0; i < e; i++) {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int startVertex;
    cin >> startVertex;

    g.DFS(startVertex);

    return 0;
}