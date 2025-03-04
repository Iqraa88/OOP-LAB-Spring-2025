#include<iostream>
using namespace std;

class Device{

    protected:
    int deviceID;
    bool status;

    public:
    Device(int deviceID, bool status): deviceID(deviceID), status(status){}
    
    void displayDetails(){
        cout<<"--------------------"<< endl;
        cout<<" Device ID: "<< deviceID<< " "<< endl;
        cout<<" Device Status: "<< status<< " "<< endl;
    }
    
};

class SmartPhone: public Device{
    protected:
    float screenSize;

    public:
    SmartPhone(int deviceID, bool status, float screenSize): Device(deviceID, status), screenSize(screenSize){}

    void displaySmartPhoneDetails(){
        Device::displayDetails();
        cout<<" Screen Size: "<< screenSize<< " "<< endl;
    }
};

class SmartWatch: public Device{

    protected:
    bool heartRateMonitor;

    public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor): Device(deviceID, status), heartRateMonitor(heartRateMonitor){}

    void displaySmartWatchDetails(){
        Device::displayDetails();
        cout<<" Heart Rate Monitor: "<< heartRateMonitor<< " "<< endl;
    }

};

class SmartWearable: public SmartPhone, public SmartWatch{

    int stepCounter;

    public:
    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter): SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter){}

    void displaySmartWearable(){

        SmartPhone::displaySmartPhoneDetails();
        cout<<" Heart Rate Monitor: "<< heartRateMonitor<< " "<< endl;
        cout<< "Step Counter: "<< stepCounter<< " "<< endl;
        cout<<"--------------------------------"<< endl;
    }
};


int main()
{

    SmartWearable sW(2001, true, 5.5, false, 100);
    sW.displaySmartWearable();
  
 return 0;
}