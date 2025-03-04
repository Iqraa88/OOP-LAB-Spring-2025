#include<iostream>
#define MAX_EMP 10
#define MAX_PROJ 10
using namespace std;

class Project;

class Employee{

    string name;
    string designation;
    int count;
    Project *projectAssigned[MAX_PROJ];

    public:
    Employee(string name, string desig, int count=0): name(name), designation(desig), count(count){
        
        
     }


    void assignProject(Project *p){
        if(count< MAX_PROJ){
        projectAssigned[count]= p;
        count++;
    }
        
    }
    string getName(){return name;}
    void displayDetails();
    
    




};


class Project{
    string title;
    string deadLine;
    int empCount;
    Employee *emp[MAX_EMP];

    public:

    Project(){}

    Project(string title, string dead, int empCount=0): title(title), deadLine(dead), empCount(empCount){}

    void addEmployees(Employee *e){
        if(empCount < MAX_EMP){
        
             emp[empCount]= e;
            e->assignProject(this);
            empCount++;
        }
        else{
            cout<< "Capacity Full! "<< endl;
        }
    }

    string getTitle(){return title;}

    void displayDetails(){
        cout<<"-------------------------"<< endl;
        cout<<"Project Title: "<< title<< " " << endl;
        cout<<"Project Deadline: "<< deadLine<< " " << endl;
        cout<<"Total Employees in Project : "<< empCount<< " " << endl;
        for(int i=0; i<empCount; i++){
        cout<<"Employee "<< i+1<< " : "<< emp[i]->getName()<< " "<< endl;
        }

        cout<<"-------------------------"<< endl;
    }

};

void Employee::displayDetails(){
   
        cout<<"-------------------------"<< endl;
        cout<<" Employee Name: "<< name<< " " << endl;
        cout<<"Designation: "<< designation<< " " << endl;
        cout<<"Total Projects Assigned : "<< count<< " " << endl;
        for(int i=0; i<count; i++){
        cout<<"Project "<< i+1<< " : "<< projectAssigned[i]->getTitle()<< " "<< endl;
        }

        cout<<"-------------------------"<< endl;
    
}


int main(){

    Employee e1("Iqra", "Assistant");
    Employee e2("Maha", "SLA");

    Project p1("English", "3 Weeks");
    Project p2("PF", "2 Weeks");
    Project p3("OOP", "1 Week");

    p1.addEmployees(&e1);
    p1.addEmployees(&e2);
    p2.addEmployees(&e1);

    e1.displayDetails();
    e2.displayDetails();

    p1.displayDetails();
    p2.displayDetails();

  
 return 0;
}