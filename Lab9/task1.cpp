#include<iostream>
using namespace std;

class Patient{

protected:
    string name;
    string id;

public:

    Patient(string name, string id): name(name), id(id){}
    virtual void displayTreatment ()const=0;
    virtual void calculateCost()=0;   
    virtual ~Patient(){}
    

};

class InPatient: public Patient{

    public:
    InPatient(string name, string id): Patient(name, id){}

    void displayTreatment()const{
        cout<<"----------------------------------"<< endl;
        cout<<" Name of InPatient: "<< name<< " "<< endl;
        cout<< "PatientID: "<< id<< " "<< endl;
        cout<< "Treatment Includes: "<< endl;
        cout<< "1. Doctor Consultation."<< endl;
        cout<< "2. Surgery."<< endl;
        cout<< "3. Physical Therapy."<< endl;
        cout<< "4. Monitoring & Room Allocation."<< endl;

    }

    void calculateCost(){
        cout<<"----------------------------------"<< endl;
        cout<<" Dear "<< name<< " , Your treatment costs are as following: "<< endl;
        cout<< "- Consultation Fee: 2500"<< endl;
        cout<< "- Surgery: 10000"<< endl;
        cout<< "- Physical Therapy: 4000"<< endl;
        cout<< "- Monitoring & Room Charges: 7000"<< endl;

        double totalCost= 2500+10000+4000+7000;
        cout<<" Your Total Charges are: "<< totalCost<< " PKR"<< endl;

    }

};

class OutPatient: public Patient{

    public:
    OutPatient(string name, string id): Patient(name,id){}

    void displayTreatment()const{
        cout<<"----------------------------------"<< endl;
        cout<< "Name of OutPatient: "<< name<< " "<< endl;
        cout<< "PatientID: "<< id<< " "<< endl;
        cout<<" Your Treatment Includes: "<< endl;
        cout<<" 1. Doctor Consultation."<< endl;
        cout<<" 2. Medicines."<< endl;
    }

    void calculateCost(){
        cout<<"----------------------------------"<< endl;
        cout<<" Dear "<< name<< " , Your treatment costs are as following: "<< endl;
        cout<< "- Consultation Fee: 2500"<< endl;
        cout<< " - Medicines: 2000"<< endl;

        double totalCost= 2500+2000;
        cout<< "Your Total Charges are: "<< totalCost<< " "<< endl;
    }

};

int main()
{

Patient *inPatient= new InPatient("Amna", "NU-I99");
inPatient->displayTreatment();
inPatient->calculateCost();

    Patient *outPatiennt= new OutPatient("Afsah", "NU-O100");
    outPatiennt->displayTreatment();
    outPatiennt->calculateCost();

    delete inPatient;
    delete outPatiennt;

  
 return 0;
}