#include<iostream>
using namespace std;

class Elevator{
    virtual void moveToFloor(int initialFloor,int targetFloor){
        //  empty 
    }  
};


class PassengerElevator : public Elevator{
    public:
    void moveToFloor(int initialFloor,int targetFloor)override{
        cout<<"Elevator Type: Passenger, Initial Floor: "<<initialFloor<<", Target Floor: "<<targetFloor<<endl;
    }
};


class FreightElevator : public Elevator{
    public:
    void moveToFloor(int initialFloor,int targetFloor)override{
        cout<<"Elevator Type: Freight, Initial Floor: "<<initialFloor<<", Target Floor: "<<targetFloor<<endl;
    }
};


int main(){
    int numElevators;
    cin>>numElevators;
    
    for(int i=0;i<numElevators;i++){
        char elevatorType;
        int initialFloor,targetFloor;
        cin>>elevatorType>>initialFloor>>targetFloor;
        
        if(elevatorType=='P'|| elevatorType=='p'){
            PassengerElevator passengerElevator;
            
            passengerElevator.moveToFloor(initialFloor,targetFloor);
            
        }else if(elevatorType=='F' || elevatorType=='f'){
            FreightElevator freightelevator;
            freightelevator.moveToFloor(initialFloor,targetFloor);
        }
    }
    
    return 0;
}