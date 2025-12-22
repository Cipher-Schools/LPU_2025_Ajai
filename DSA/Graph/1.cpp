#include<iostream>
#include <vector>
using namespace std;
     
// A---B
// |   | 
// C---D


class Graph{
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

    public:
        Graph(int V){
            this->V=V;
            adj.resize(V);
        }
        
        
        void addEdge(int u , int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        
        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<"vertex"<<i<<": ";
                for(int x: adj[i]){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
        
        
};
    
    
int main(){
    Graph g(5);   // 5 vertices (0 to 4)
    
    
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    
    // v -> number of nodes
    // addEdge(u,v)  connect u to v
    
    g.printGraph();
    return 0;
}
     