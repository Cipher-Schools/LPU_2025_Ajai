#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge{
    int u; // source
    int v; // destination
    int w; // weight
};

int main(){
    int V=3; // number of vertices
    int E=3; // number of edges
    
    vector<Edge> edges;
    
    edges.push_back({0,1,1});   //A->B
    edges.push_back({0,2,4});   //A->C 
    edges.push_back({2,1,-5});  // C->B
    
    int src=0;
    
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    
    for(int i=1;i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;
            
            
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
            
            
        }
    }
    

    // negative values 
    for(int j=0;j<E;j++){
        int u=edges[j].u;
        int v=edges[j].v;
        int w=edges[j].w;
        
        
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            cout<<"negative weight detected"<<endl;
            
            return 0;
        }
    }
    
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
        
  return 0;  
}