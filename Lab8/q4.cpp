#include<iostream>
using namespace std;

class Car{

    string model;
    long int price;

    friend class InventoryManager;
    friend void compareCars(const Car &obj1, const Car &obj2);

    public:
    Car(string model, long int price): model(model), price(price){}



};
class InventoryManager{

    public:
    void displayDetails(Car &car){
        cout<< "-------------------------"<< endl;
        cout<<"  Displaying Car Details "<< endl;
        cout<< " Model: "<< car.model<< " "<< endl;
        cout<< " Price: "<< car.price<< " "<< endl;
        cout<< "-------------------------"<< endl;
    }

    void updateCar(Car &c){
        
        long int price;
        cout<< "Whats the new price? "<< endl;
        cin>> price;
        c.price= price;
        cout<<"----------------------------------"<< endl;
        cout<< "Price Updated Successfully!"<< endl;
    }
};

void compareCars(const Car &obj1, const Car &obj2){
    cout<< "-------------------------------"<< endl;
    if(obj1.price> obj2.price){
        cout<<"Car "<< obj1.model<< " is expensive as compared to Car " << obj2.model<< " ."<< endl;
    }
    else if (obj1.price < obj2.price){
        cout<<"Car "<< obj2.model<< " is expensive as compared to Car " << obj1.model<< " ."<< endl;

    }
    else{
        cout<< "Prices of Both Cars are equal."<< endl;
    }
}

int main()
{

    Car car1("Honda Civic", 4500000);
    Car car2("Toyota Corolla", 4200000);
    InventoryManager system;

    system.displayDetails(car1);
    system.displayDetails(car2);

    system.updateCar(car1);


    compareCars(car1, car2);

  
 return 0;
}