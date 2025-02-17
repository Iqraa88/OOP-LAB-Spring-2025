#include<iostream>
using namespace std;

class Car{

string brand;
string model;
float rentalPrice;
bool availablityStatus;


public:


Car(string br, string mod, float pr, bool st){
     brand= br;
    model= mod;
    rentalPrice= pr;
    availablityStatus= st;
}

void updateDetails(string b, string m, float price, bool status){
    brand= b;
    model= m;
    rentalPrice= price;
    availablityStatus= status;
}
void checkAvailablity(){
    cout<< "-------------------------------------"<< endl;
    cout<< "Checking Availablity...."<< endl;
    if(availablityStatus== true){
        cout<<" Car is Avaialable!"<< endl;
    }
    else{
        cout<<" Car Unavailable!"<< endl;
    }

    cout<< "-------------------------------------"<< endl;
}

void applyDiscount(float days){
    if(days>5){
        rentalPrice= rentalPrice*(1-0.05);
    }
    else if(days> 10){
        rentalPrice= rentalPrice*(1-0.1);
    }
}

void rentalRequest(){
   
    cout<< "Please Wait! Your Request is being processed!"<< endl;
    float days;
    if(availablityStatus== true){
        cout<< "How many days you want to rent for?"<< endl;
        cin>> days;
        applyDiscount(days);
        
        cout<< "Car Rented Successfully!"<< endl;
        availablityStatus= false; 

}
else{
    cout<<" Car cannot be rented at the moment!"<< endl;
}

cout<< "------------------------------------"<< endl;
    
}




void displayDetails(){
    cout<< "----------------------------------"<< endl;
    cout<< "Displaying Your Car Details: "<< endl;
    cout<< "Brand: "<< brand<< " "<< endl;
    cout<< "Model: "<< model<< " "<< endl;  
    cout<< "Rental Price: "<< rentalPrice<< " "<< endl;
   
}
};

int main(){



Car c1("ABC", "HIJ", 300000, true);
c1.displayDetails();
c1.checkAvailablity();
c1.rentalRequest();
c1.displayDetails();




    return 0;
}


