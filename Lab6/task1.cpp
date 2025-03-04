#include <iostream>
using namespace std;

class Employee
{
  private:
    string name;
    float salary;

    public:
    Employee(string name, float salary) : name(name), salary(salary) {}

    void displayDetails(){
        cout<<"--------------------"<< endl;
        cout<<"Name: "<< name<< " "<< endl;
        cout<<"Salary: "<< salary<< " "<< endl;
    }      
};

class Manager: public Employee
{
    private:
    float bonus;

    public:
    Manager(string name, float salary, float bonus): Employee(name, salary), bonus(bonus){}

    
  void display() {
    Employee::displayDetails();
    cout<<"Bonus: "<< bonus<< " "<< endl;

  }
    
    

};

int main()
{
    Manager m1("Amna", 45000.00, 2000.00);
    m1.display();

    return 0;
}
