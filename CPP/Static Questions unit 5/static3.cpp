#include<iostream>
#include<iomanip>

using namespace std;


int main(){
    int tickets;
    
    cin>>tickets;
    
    int* prices = new int[tickets];
    
    for(int i=0;i<tickets;i++){
        cin>>prices[i];
    }
    
    double total=0;
    for(int i=0;i<tickets;i++){
        total+=prices[i];
    }
    
    cout<<fixed<<setprecision(2);
    cout<<"Total: "<<total<<endl;
    if(tickets>=3){
        double discount= total*0.10;
        cout<<"Discount: "<<discount<<endl;
        cout<<"Final: "<<total-discount<<endl;
        
    }else{
        cout<<"No discount"<<endl;
    }
    
    
    delete[] prices;
    
    return 0;
}