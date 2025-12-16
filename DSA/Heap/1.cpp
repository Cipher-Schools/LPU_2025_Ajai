#include<bits/stdc++.h>

using namespace std;

// 10 -> 5 -> 20->2
// 10
// 5 10 
// 5 10 20 
// 2 , 5 , 20 , 10



// // hepify done
// 2 , 5 , 20 , 10 

class MinHeap{
    
    vector<int> heap;
    
    void heapifyup(int i){
        while(i>0){
            int parent=(i-1)/2;
            if(heap[parent]>heap[i]){
                swap(heap[parent],heap[i]);
                i=parent;
            }else{
                break;
            }
        }
    }
    
    
    void heapifydown(int i){
        int n=heap.size();
        
        while(true){
            int left= 2*i+1;
            int right=2*i+2;
            int smallest=i;
            
            if(left<n&& heap[left]<heap[smallest]){
                smallest=left;
            }
            
            if(right<n && heap[right]< heap[smallest]){
                smallest=right;
            }
            
            if(smallest!=i){
                swap(heap[i],heap[smallest]);
                i=smallest;
            }else{
                break;
            }
        }
    }
    
    public:
    void insert(int val){
        heap.push_back(val);
        heapifyup(heap.size()-1);
    }
    
    // remove minimum element
    
    int extractMin(){
        if(heap.empty()){
            cout<<"Heap is empty]\n";
            return -1;
        }
        
        int minVal= heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        
        if(!heap.empty()){
            heapifydown(0);
        }
            return minVal;
        
    }    
    
    
    void printHeap(){
        for(int x: heap){
            cout<<x<<" ";
            
        }
        cout<<endl;
    }
    
    
};


int main(){
    MinHeap h;
    
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);
    
    cout<<"Heap elements:";
    h.printHeap();
    
   cout<<"element which is minimum deleted" <<h.extractMin()<<endl;
    
    cout<<"Heap elements:";
    h.printHeap();
    
    
    return 0;
}



