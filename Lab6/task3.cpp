#include <iostream>
using namespace std;

class Person
{
    protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void displayDetails()
    {
        cout << "--------------------" << endl;
        cout << " Name: " << name << " " << endl;
        cout << " Age: " << age << " " << endl;
    }
};
class Teacher: public Person
{
    protected:
    string subject;

    public:
    Teacher(string name, int age, string subject) :Person(name, age), subject(subject) {}

    void displayTeacher()
    {
       Person::displayDetails();
        cout << " Subject: " << subject << " " << endl;
    }
};
class Researcher: public Person
{
    protected:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayResearcher()
    {
        Person::displayDetails();
        cout << " Research Area: " << researchArea << " " << endl;
    }
};
class Professors: public Teacher, public Researcher
{
    protected:
    int publications;

public:
    Professors(string name, int age, string subject, string researchArea, int publications): Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}


    void displayProfessor(){
        
      Teacher::displayDetails();
      cout<<"Research Area: "<< Researcher::researchArea<< " "<< endl;
      cout<< "Publications: "<< publications<< " "<< endl;
      cout<<"-------------------------"<< endl;
      
        
    }

};
    

int main()

{

    Professors p1("Kashif", 30, "Programming Fundamentals", "Computer Science", 4);
    p1.displayProfessor();

    return 0;
}