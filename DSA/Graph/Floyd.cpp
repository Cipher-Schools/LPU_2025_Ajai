#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

void floydWarshall(vector<vector<int>>& dist,int V){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}



int main(){
    int V=4;
    
    
    vector<vector<int>> dist={
        
            {0,5,INF,10},
            {INF,0,3,INF},
            {INF,INF,0,1},
            {INF,INF,INF,0}
        };
        
    
    floydWarshall(dist,V);
    
    cout<<"All pairs Shortest Path:\n";
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF){
                cout<<"INF";
            }else{
                cout<<dist[i][j]<<" ";
            }
            
        }
    cout<<endl;
        
    }
    
    
    
    
    
    
    return 0;
}

// 0   1  2  3 vertices
// 0   5  8  9                  0th row
// inf 0  3  4                  1st row 

