#include<iostream>
using namespace std;

class WeatherSensor{

    public:

    virtual void readData()=0;
    virtual void displayReport()=0;

};

class Thermometer: public WeatherSensor{

    public:
    void readData(){
        cout<<"-------------------------------"<< endl;
        cout<< "Reading Data from Thermometer..."<< endl;
    }

    void displayReport(){
    
        cout<<"-------------------------------"<< endl;
        cout<<" Displaying Thermometer Report..."<< endl;
    }
};

class Barometer: public WeatherSensor{

    public:
    void readData(){
        cout<<"-------------------------------"<< endl;
        cout<< "Reading Data from Barometer..."<< endl;
    }

    void displayReport(){
    
        cout<<"-------------------------------"<< endl;
        cout<<" Displaying Barometer Report..."<< endl;
    }
};


int main()
{

    WeatherSensor *sensor;

    sensor= new Thermometer();
    sensor->readData();
    sensor->displayReport();
    delete sensor;

    sensor= new Barometer();
    sensor->readData();
    sensor->displayReport();
    delete sensor;
  
 return 0;
}