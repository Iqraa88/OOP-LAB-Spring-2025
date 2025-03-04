#include<iostream>
using namespace std;

class Vehicle{

    string brand;
    int speed;

    public:
    Vehicle(string brand, int speed): brand(brand), speed(speed){}

    void displayDetails(){
        cout<< "-------------"<< endl;
        cout<< "Brand: "<< brand<< " " << endl;
        cout<< "Speed: "<< speed<< " " << endl;
    }

};
class Car: protected Vehicle{

    int seats;

    public:

    Car(string brand, int speed, int seats): Vehicle(brand, speed), seats(seats){}

    void display(){
        Vehicle::displayDetails();
        cout<< "Seats: "<< seats<< " "<< endl;
    }

};
class ElectricCar : public Car{

    int batteryLife;

    public:
    ElectricCar(string brand, int speed, int seats, int batteryLife): Car(brand, speed, seats), batteryLife(batteryLife){}

    void displayElectricCar(){
          Car::display();
          cout<<"Battery Life: "<< batteryLife<< " "<< endl;
          cout<<"-----------------------------"<< endl;
    }

};

int main()
{

    ElectricCar e1("Toyota", 120, 4, 3);
    e1.displayElectricCar();
  
 return 0;
}