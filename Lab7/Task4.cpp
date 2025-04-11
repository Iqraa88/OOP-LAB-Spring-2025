#include<iostream>
using namespace std;

class Person{

    protected:
    string name;
    int age;
    string contactNum;
    
    public:
    Person(){}
    Person(string name, int age, string contactNum): name(name), age(age), contactNum(contactNum){}

    virtual void displayInfo(){
        cout<<"----------------------"<< endl;
        cout<< "Name: "<< name<< " "<< endl;
        cout<< "Age: "<< age<< " "<< endl;
        cout<< "Contact Number: "<< contactNum<< " "<< endl;
    }

    virtual void updateInfo(string name, int age, string contactNum){
        this->name= name;
        this->age= age;
        this->contactNum= contactNum;
        cout<<"----------------------------------"<< endl;
        cout<< "Information Updated Successfully!"<< endl;
    }

};


class Patient: public Person{

    
    string patientID;
    string medicalHistory;
    string doctorAssigned;

    public:

    Patient(){}
    Patient(string name, int age, string contactNum, string patientID, string medicalHistory, string doctorAssigned ): Person(name, age, contactNum), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned){}


    void displayInfo()override{
        Person::displayInfo();
        cout<< "Patient ID: "<< patientID<< " "<< endl;
        cout<< "Medical History: " << medicalHistory<< " "<< endl;

    }

    string getName(){return name;}

    
};
class Doctor: public Person{

    string specialization;
    double consultationFee;
    Patient *patientsList[2];
    

    public:

    Doctor(){}
    Doctor(string name, int age, string contactNum, string specialization, double consultationFee, Patient *patientsList[] ): Person(name, age, contactNum), specialization(specialization), consultationFee(consultationFee){

        for(int i=0; i<2; i++){
            this->patientsList[i]= patientsList[i];
        }
    }

    void displayInfo()override{
        Person::displayInfo();
        cout<< "Specialization: "<< specialization<< " "<< endl;
        cout<< "Consultation Fee: "<< consultationFee<< " "<< endl;
        cout<< "Patients List: "<< endl;
        for(int i=0; i<2; i++){
            cout<< " - "<< patientsList[i]->getName()<< " "<< endl;
        }
    }


};

class Nurse: public Person{

    string assignedWard;
    string shiftTimings;

    public:
    Nurse(string name, int age, string contactNum, string assignedWard, string shiftTimings): Person(name, age, contactNum), assignedWard(assignedWard), shiftTimings(shiftTimings){}

    void displayInfo()override{
        Person::displayInfo();

        cout<< " Assigned Ward: "<< assignedWard<< " "<< endl;
        cout<< " Shift Timings: "<< shiftTimings<< " "<< endl;
    }

};

class Administartor: public Person{

    string department;
    double salary;

    public:
    Administartor(string name, int age, string contactNum, string department, double salary): Person(name, age, contactNum), department(department), salary(salary){
    }

    void updateInfo(string name, int age, string contactNum, string department, double salary){

        Person::updateInfo(name,age,contactNum);
        this->department= department;
        this->salary= salary;

    }
};


int main()
{

    Person *ptr;

    Patient p1("Ali", 22, "+923333333333", "P#99", "Kidney Transplant", "Dr.Rahim" );
    Patient p2("Shiza", 33, "+9222222222", "P#109", "Heart Surgery ", "Dr. Faisal" );
    Patient* patientLists[2]= {&p1,&p2};

    Doctor d1("Dr Faisal", 45, "+9244444444", "Cardiologist", 2000, patientLists);

    Nurse n1("Alisa", 35, "+9288888888", "Ward-9", "Day" );

    Administartor Admin("Fakhar", 40, "+92111111111", "HR", 100000 );

    ptr= &p1;
    ptr->displayInfo();
    ptr= &p2;
    ptr->displayInfo();

    ptr=&d1;
    ptr->displayInfo();

    ptr= &n1;
    ptr->displayInfo();

    ptr=&Admin;
    Admin.updateInfo("Rahul", 33, "+927777777777", "HR", 150000);
    ptr->displayInfo();



  
 return 0;
}