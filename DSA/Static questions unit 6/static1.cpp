#include <iostream>
#include <queue>
using namespace std;
void BFS(int graph[100][100], int numCities, int source) {
    bool visited[100] = {false};
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while (!q.empty()) {
        int currentCity = q.front();
        q.pop();
        cout << currentCity << " ";
        for (int i = 0; i < numCities; i++) {
            if (graph[currentCity][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int numCities, numConnections;
    cin >> numCities >> numConnections;
    int graph[100][100] = {0};
    for (int i = 0; i < numConnections; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    int source;
    cin >> source;
    BFS(graph, numCities, source);
    return 0;
}