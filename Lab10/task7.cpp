#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  
    ofstream file("sensor_log.txt", ios::app);
    if(file.is_open()){
        file<<"Sensor 1: 25.5C\n";

        streampos position = file.tellp();
        cout<< "Current Position: " << position<< " "<< endl;
    
        file<<"Sensor 2: 98.1%RH\n";
        position= file.tellp();
        cout<< "Current Position: " << position<< " "<< endl;

        file.close();
    }
    else{
        cerr<<"Error: Unable to open file."<< endl;
    }

 return 0;
}