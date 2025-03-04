#include <iostream>
using namespace std;

class AlarmSystem
{

    string securityLevel;

public:
    AlarmSystem(string secLevel) : securityLevel(secLevel) {}

    
string getLevel(){return securityLevel;}


};


class SmartHome
{
    string address;
    AlarmSystem alarm;

public:
    SmartHome(string address, AlarmSystem alarm) : address(address), alarm(alarm) {
        cout<<" Alarm System Implemented Successfully!"<< endl;
    }

    void displayDetails(){
        cout<<"------------------"<< endl;
        cout<< "Home Address: "<< address<< " "<< endl;
        cout<<" Alarm System: "<< alarm.getLevel()<< endl;
        cout<<"------------------"<< endl;

    }
    ~SmartHome()
    {
        cout<<" Alarm System Deleted!"<< endl;
        cout<< "SmartHome Deleted!"<< endl;
    }
};

int main()
{

    AlarmSystem a1("High");
    AlarmSystem a2("Low");
    AlarmSystem a3("Medium");

    SmartHome s1("Hollywood, Los Angeles", a1);
    SmartHome s2("SeaView Rd.23",a2);
    SmartHome s3("Near Central Park", a3);

    s1.displayDetails();
    s2.displayDetails();
    s3.displayDetails();



    return 0;
}