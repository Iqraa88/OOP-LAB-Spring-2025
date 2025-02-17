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



Car(const Car &obj){
    brand= obj.brand;
    model= obj.model;
    rentalPrice= obj.rentalPrice;
    availablityStatus= obj.availablityStatus;
}

~ Car(){
    cout<< "Object Removed!"<< endl;
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
Car c2(c1);
c1.updateDetails("poq", "rst", 28500, false);
c1.displayDetails();
cout<<"-----------------------------"<< endl;
c2.displayDetails();




    return 0;
}


