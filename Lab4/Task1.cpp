#include<iostream>
using namespace std;

class Car{

string brand;
string model;
float rentalPrice;
bool availablityStatus;

public:
Car(){
    brand= "Unknown";
    model= "Genric";
    rentalPrice= 0.0;
    availablityStatus= true;
}

void updateDetails(string b, string m, float price, bool status){
    brand= b;
    model= m;
    rentalPrice= price;
    availablityStatus= status;
}
void checkAvailablity(){
    cout<< "Checking Availablity........"<< endl;
    if(availablityStatus== true){
        cout<<" Car is Avaialable!"<< endl;
    }
    else{
        cout<<" Car Unavailable!"<< endl;
    }
}

void rentalRequest(){
    cout<< "Your Request is being processed...."<< endl;
    if(availablityStatus== true){
        cout<< "Car Rented Successfully!"<< endl;
        availablityStatus= false; 
}
else{
    cout<<" Car cannot be rented at the moment!"<< endl;
}
    
}

void displayDetails(){
    cout<< "Displaying Your Car Details: "<< endl;
    cout<< "Brand: "<< brand<< " "<< endl;
    cout<< "Model: "<< model<< " "<< endl;  
    cout<< "Rental Price: "<< rentalPrice<< " "<< endl;
   
}
};

int main(){

Car c1;


c1.updateDetails("ABC", "HIJ", 25000.00, true);
c1.displayDetails();
c1.checkAvailablity();
c1.rentalRequest();



    return 0;
}

