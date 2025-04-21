#include<iostream>
using namespace std;

class MenuItem{

    protected:
    string dishName;
    double price;

    public:
    MenuItem(string dishName, double price): dishName(dishName), price(price){}
    virtual void showDetails()=0;
    virtual void prepeare()=0;
    virtual ~MenuItem(){}

};

class Appetizer: public MenuItem{

    public:
    Appetizer(string dishName, double price): MenuItem(dishName, price){}
    
    void showDetails(){
        cout<<"------------------------"<< endl;

    cout<<"Appetizer - DishName: "<< dishName<< " "<< endl;
    cout<< "Price: Rs. "<< price<< " /-"<< endl;
    }

    void prepeare(){
        cout<<"------------------------"<< endl;
    cout<< "Please Wait, While We are prepearing your appetizer ( "<< dishName<< "  )..."<< endl;}
};

class MainCourse: public MenuItem{

    public:
    MainCourse(string dishName, double price): MenuItem(dishName, price){}

    void showDetails(){
        cout<<"------------------------"<< endl;

        cout<<" MainCourse - DishName: "<< dishName<< " "<< endl;
        cout<< "Price: Rs. "<< price<< " /-"<< endl;
        }


    void prepeare(){
        cout<<"------------------------"<< endl;
        cout<< "Please Wait, While We are prepearing your maincourse ( "<< dishName<< "  )..."<< endl;}

};
int main()
{

    MenuItem *appetizer= new Appetizer(" Mozzarella Sticks", 750);
    appetizer->showDetails();
    appetizer->prepeare();
    
    delete appetizer;

    MenuItem *mainCourse= new MainCourse("MeatBalls", 1050);
    mainCourse->showDetails();
    mainCourse->prepeare();

    delete mainCourse;

  
 return 0;
}