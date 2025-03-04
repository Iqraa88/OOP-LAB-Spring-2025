#include<iostream>
using namespace std;


class Doctor{

    string name;
    string specialization;
    string experience;

    public:
    Doctor(){}
    Doctor(string name, string specialization, string experience): name(name), specialization(specialization), experience(experience){}


    string getName(){return name;}

};

class Hospital{

        string name;
        string address;
        int doctCount;
        int capacity;
        Doctor *workingDoctors;

        public:
        Hospital(string name, string address, int capacity, int count=0): name(name), address(address), capacity(capacity), doctCount(count){
        
            workingDoctors= new Doctor[capacity];
            
        }

        void assignDoctors(Doctor *d){
            if(doctCount < capacity){
                workingDoctors[doctCount]= *d;
                doctCount++;
            }
            else{
                cout<<"Capacity Full!!!"<<endl;
            }
            
        }

        void displayDetails(){
            cout<<"-------------------"<< endl;
            cout<<" Hospital Name: "<< name<< " "<< endl;
            cout<<" Hospital Address: "<< address<< " "<< endl;
            cout<<" Total Doctors: "<< doctCount<< " " << endl;
            for(int i=0; i<doctCount; i++){
            cout<< "Doctor "<< i+1<< " : "<< workingDoctors[i].getName()<< " "<< endl;
            }
            cout<<"-------------------"<< endl;
        }

        ~ Hospital(){
            delete[] workingDoctors;
        }

};
int main()
{

    Doctor d1("Waqar", "Dentist", "10 years");
    Doctor d2("Nazir", "Child Specialist", "12 years");
    Doctor d3("Bilal", "Surgeon", "5 years");

    Hospital h1("PNS Shifa", "DHA ", 10);
    h1.assignDoctors(&d1);
    h1.assignDoctors(&d2);
    h1.assignDoctors(&d3);

    h1.displayDetails();

  
 return 0;
}