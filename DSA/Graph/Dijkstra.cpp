#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 0  {1,2}

typedef pair<int,int> pii; // 

void dijkstra(int src, vector<vector<pii>>& graph,int V){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dist(V,INT_MAX);
    
    dist[src]=0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int currDist = pq.top().first;
        int u= pq.top().second;
        pq.pop();
        
        if(currDist> dist[u]) continue;
        
        for(auto edge : graph[u]){
            int v = edge.first;
            int weight = edge.second;
            
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
        
    }
    
    cout<<" vertext\tDistance from source\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int main() {
    int V=5;
    vector<vector<pii>> graph(V);
    // vertex,distance
    graph[0].push_back({1,2});
    graph[0].push_back({4,1});
    graph[1].push_back({2,3});
    graph[2].push_back({3,6});
    graph[4].push_back({2,2});
    graph[4].push_back({3,3});
    
    dijkstra(0,graph,V);
    

    return 0;
}