
void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void maxHeapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right= 2*i+2;
    
    if(left<n && arr[left]>arr[largest]){
        largest= left;
    }
    if(right<n && arr[right]> arr[largest]){
        largest = right;
    }
    
    if(largest!=i){
        swap(arr,i,largest);
        maxHeapify(arr,n,largest);
    }
}

bool deleteFirstEven(int arr[],int& n){
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            arr[i]=arr[n-1];
            n--;
            maxHeapify(arr,n,i);
            return true;
        }
    }
    return false;
}


void buildmaxHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}


void insertIntoMaxHeap(int arr[], int& n, int value){
    n++;
     int i=n-1;
     arr[i]=value;
     
     
     while(i>0 && arr[(i-1)/2]<arr[i]){
         swap(arr,i,(i-1)/2);
         i=(i-1)/2;
     }
}


bool deleteFiestEven(int arr[],int& n){
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            arr[i]=arr[n-1];
            n--;
            maxHeapify(arr,n,i);
            return true;
        }
    }
    
    return false;
}


void printMaxHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}