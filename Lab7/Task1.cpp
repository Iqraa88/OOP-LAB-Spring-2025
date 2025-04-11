#include<iostream>
using namespace std;

class Device{

string deviceID;
string deviceName;
bool status;
string location;

public:

Device(){}
Device(string deviceID, string deviceName, bool status, string location): deviceID(deviceID), deviceName(deviceName), status(status), location(location){}


virtual void turnOn(){
    status= true;
}

virtual void turnOff(){
    status= false;
}

virtual string getStatus(){
    if(status){return "On";}
    else{return "Off";}
}

virtual void displayInfo(){

cout<<"------------------------------"<<endl;
cout<<"Device ID: "<< deviceID<< " "<< endl;
cout<<"Device Name: "<< deviceName<< " "<< endl;
if(status=true){
    cout<<" Device Status: On "<< endl;
}
else{
    cout<<" Device Status: Off"<< endl;
}
cout<<"Device Location: "<< location<< " "<< endl;
cout<<"------------------------------"<<endl;
}

};

class Light: public Device{

    int brightnessLevel;
    string colorMode;

    public:
    Light(string deviceID, string deviceName, bool status, string location, int brightnessLevel, string colorMode): Device(deviceID, deviceName, status, location), brightnessLevel(brightnessLevel), colorMode(colorMode){}

    using Device::displayInfo;

    void displayInfo(){
        cout<<"-----------------------"<< endl;
        cout<< "Brightness Level: "<< brightnessLevel<< " "<< endl;
        cout<< "Color Mode: "<< colorMode<< " "<< endl;
        cout<<"-----------------------"<< endl;
    }

};

class Thermostat: public Device{

    float temprature;
    string mode;
    float targetTemprature;

    public:

    Thermostat(string deviceID, string deviceName, bool status, string location, float temprature, string mode, float targetTemprature): Device(deviceID, deviceName, status, location), temprature(temprature), mode(mode), targetTemprature(targetTemprature){}
    using Device::getStatus;

    string getStatus(){
        return to_string(temprature);
    }

};

class SecurityCamera: public Device{



    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

    public:

    SecurityCamera(string deviceID, string deviceName, bool status, string location, string resolution, bool recordingStatus, bool nightVisionEnabled ): Device(deviceID, deviceName, status, location), resolution(resolution), recordingStatus(recordingStatus), nightVisionEnabled(nightVisionEnabled){}

    using Device::turnOn;

    void turnOn(){
        recordingStatus= true;
    }

};

class SmartPlug: public Device{


    bool powerConsumption;
    int timerSetting;

    public:

    SmartPlug(string deviceID, string deviceName, bool status, string location, bool powerConsumption, int timerSetting): Device(deviceID, deviceName, status, location), powerConsumption(powerConsumption), timerSetting(timerSetting){}
    using Device::turnOff;

    void turnOff(){
        powerConsumption= false;
    }
};



int main()
{
    
    Device *ptr;
    
    Light l1("L#1", "LED Light", false, "Room", 100, "RGB");
    ptr= &l1;
    
    ptr->displayInfo();
    ptr->turnOn();
    ptr->getStatus();

    Thermostat t1("T#1", "HomeThermostat", false, "Kitchen", 56.6, "Heating", 100.00 );
    ptr= &t1;
    ptr->displayInfo();
    ptr->turnOn();
    ptr->getStatus();

    SecurityCamera s1("SC#1", "HomeCamera", true, "Main Entrance", "4K", false, true);
    ptr= &s1;
    ptr->displayInfo();
    ptr->turnOn();
    ptr->getStatus();

    SmartPlug p1("SP#1", "HomePlug", false, "Dinning Hall", true, 60 );
    ptr= &p1;
    ptr->displayInfo();
    ptr->turnOff();
    ptr->getStatus();


    

  
 return 0;
}
