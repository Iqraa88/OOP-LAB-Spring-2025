#include<iostream>
using namespace std;

class Apartment{

    string ID;
    string address;
    string *ownerName;

    public:

    Apartment(string ID, string address, string name): ID(ID), address(address){

        ownerName= new string(name);
    }

    Apartment(const Apartment &obj){
        ID= obj.ID;
        address= obj.address;
        ownerName= obj.ownerName;

    }

    void displayDetails(){
        cout<<"--------------------------" << endl;
        cout<<"Apartment ID: "<<ID << " "<< endl;
        cout<<"Apartment Address: "<<address << " "<< endl;
        cout<<"Apartment Owner: "<<* ownerName << " "<< endl;
        cout<<"--------------------------" << endl; 
    }

    ~ Apartment(){
        delete ownerName;
        cout<< "DELETING!"<< endl;
    }

};


int main(){

    Apartment a1("R109", "Shahrah-e-Faisal", "Arez Khan");
    Apartment a2(a1);

    a1.displayDetails();
    a2.displayDetails();
    return 0;
}
