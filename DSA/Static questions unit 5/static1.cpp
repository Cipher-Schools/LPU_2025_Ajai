class MaxHeap{
    vector<int> heap;
    
    void heapifyUp(int i){
        while(i!=0 && heap[(i-1)/2]<heap[i]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
        
    }
    

    public:
        void insert(int value){
            heap.push_back(value);
            heapifyUp(heap.size()-1);
            
        }
        
        void printHeap(){
            for(int val : heap){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    
};

