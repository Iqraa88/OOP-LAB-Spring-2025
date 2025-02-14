#include<iostream>
using namespace std;


class Car{
string brand;
int model;
float fuelCapacity;
float currentFuelLevel;
float usedFuel;

public:

void setBrand(string name){
    brand= name;
}

void setModel(int m){
    model= m;
}

void setFuelCapacity(float cap){
    if(cap>0){
        fuelCapacity= cap;
    }
}

void setCurrentLevel(float level){
    currentFuelLevel= level;
}


void drive(float d){
    usedFuel= d*0.33;
    if(usedFuel> currentFuelLevel){
        cout<<"  Insufficient Fuel! Please Refill."<< endl;
    }
    else{
    currentFuelLevel-= usedFuel;
    cout<< "You have used "<< usedFuel<< " Fuel so far!"<< endl;
    cout<< "Your Current Fuel is: "<< currentFuelLevel<< endl;
    }
}

void reFuelTank(float refuel){
    if(refuel>0 && (refuel+ currentFuelLevel<= fuelCapacity)){
        currentFuelLevel+= refuel;
        cout<< "Tank Refueled to "<< refuel<< " ltrs."<< endl;
        cout<<" Current Fuel Level: "<< currentFuelLevel<< " " <<endl;
    }
    else{
        cout<< "There is no more capacity to refuel the tank!"<< endl;
    }
}

void statusCheck(){
    if(currentFuelLevel< 10){
        cout<<" Low Fuel! Refuel asap."<< endl;
        
    }
    else{
        cout<<"Current Fuel Level: "<< currentFuelLevel<< " ltrs. "<< endl;
    }
}


};

int main(){
 
 float dist,fuel;
 string wish;
 Car c1;

 c1.setBrand("Toyota");
 c1.setModel(2015);
 c1.setFuelCapacity(100);
 c1.setCurrentLevel(90);

 cout<<" How much meterss have you driven yet?"<< endl;
 cin>> dist;

 c1.drive(dist);
 c1.statusCheck();


 cout<< "Do you wish to Refuel the tank?"<< endl;
 cin>> wish;

 if(wish== "yes"){
    cout<<" How much fuel you wanna add?"<< endl;
    cin>> fuel;
    c1.reFuelTank(fuel);
 }
 
 


 
 
 
    return 0;
}
