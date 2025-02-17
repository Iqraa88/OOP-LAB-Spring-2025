#include<iostream>
using namespace std;

class Car{

    private:
string brand;
string model;
float rentalPrice;
bool availablityStatus;
double totalRevenue;
float days;
string regNum;



public:


Car(string br, string mod, float pr, bool st, string registNo):brand(br), model(mod), rentalPrice(pr), availablityStatus(st), regNum(registNo)
{
    totalRevenue=0;
    cout<<" Your Car has been registered!"<< endl;
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



void rentalRequest(){
   
    cout<< "Please Wait! Your Request is being processed!"<< endl;
    if(availablityStatus== true){
        cout<< "How many days you want to rent for?"<< endl;
        cin>> days;
        
        this->totalRevenue+= (this->rentalPrice* days);
        
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
cout<<" Registration Number: "<< regNum<< " "<< endl;
cout<< "Brand: "<< brand<< " "<< endl;
cout<< "Model: "<< model<< " "<< endl;  
cout<< "Rental Price: "<< rentalPrice<< " "<< endl;
cout<< "Total Revenue: "<< totalRevenue<< " "<< endl;
if(availablityStatus){
cout<< "Availablity Status: Available"<< endl;
}
else{
    cout<< "Availablity Status: Unavailable"<< endl;

}
}
};

int main(){



Car c1("ABC", "HIJ", 3000, true, "BK25");
c1.displayDetails();
c1.checkAvailablity();
c1.rentalRequest();
c1.displayDetails();







    return 0;
}


