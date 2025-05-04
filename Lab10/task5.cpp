#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class FileHandler{

    string type;
    string name;
    string id;
    string year;
    string extraData;
    string certification;

    public:

    void createFile(string filename){
    
        ofstream file (filename);
        if(file.is_open()){
          file<<"//Vehicle Database\n";
           file<< "AutonomousCar,AC101,RoboTaxi,2023,SM:4.5,CERT-AI\n";
            file<<"ElectricVehicle,EV202,VoltZ,2022,Battery:150,CERT-ECO\n";
           file<< "HybridTruck,HT303,GreenHauler,2021,Cargo:5000|Battery:75,CERT-HYBRID\n";
        file.close();
        
        }
        else{
        cerr<<"Unable to open file "<< filename<< " "<< endl;
        }
        
        }
    void readData(string filename){
    
        ifstream file(filename, ios::in);
        if(file.is_open()){
        string data;
        
        
        while(getline(file, data)){
        if(data[0]=='/' && data[1]=='/'){
        continue;
        }
            
            istringstream line(data);
            
            getline(line, type, ',');
            getline(line, name, ',');
            getline(line, id, ',');
            getline(line, year, ',');
            getline(line, extraData, ',');
            getline(line, certification, ',');
            

        if(type== "AutonomousCar" || type=="ElectricVehicle" || type== "HybridTruck"){
           

            if(type=="AutonomousCar"){
                size_t index= extraData.find(':');
                if(index!=string::npos){
                    cout<<endl;
                    cout<<"------------Colon was found at---------- "<< index<< endl;
                string extractedValue= extraData.substr(index+1);
            float softwareVersion= stof(extractedValue);
            cout<<"-------------------------------------------"<< endl;
            cout<<" ID: "<< id<< " "<< endl;
            cout<<" Software Version: "<< softwareVersion<< " "<< endl;
            }
        }
            else if(type=="ElectricVehicle"){
                size_t index= extraData.find(':');
                if(index!=string::npos){
                    cout<<endl;
                    cout<<"------------Colon was found at---------- "<< index<< endl;
                string extractedValue= extraData.substr(index+1);
            int batteryCapacity= stoi(extractedValue);
            cout<<"----------------------------------------------"<< endl;
            cout<<" ID: "<< id<< " "<< endl;
            cout<<" Battery Capacity: "<< batteryCapacity<< " "<< endl;
            }
        }
            else if(type=="HybridTruck"){
                size_t indexC= extraData.find(':');
                size_t indexB= extraData.find('|');
                if(indexC!= string::npos  && indexB!= string::npos){
                    cout<<endl;
                    cout<<"------------Colon was found at---------- "<< indexC<< endl;
                    cout<<"------------PipeSymbol was found at---------- "<< indexB<< endl;

                    string extCargo= extraData.substr(indexC+1);
                    int cargoValue= stoi(extCargo);

                    size_t colonBattery= extraData.find(':', indexB);
                    string extBattery= extraData.substr(colonBattery+1);
                    int batteryCap= stoi(extBattery);

                    cout<<"----------------------------------------------"<< endl;
                    cout<<" ID: "<< id<< " "<< endl;
                    cout<<" Cargo: "<< cargoValue<< " "<< endl;
                    cout<<" Battery Capacity: "<< batteryCap<< " "<< endl;
                }
            }
            else{
                cerr<<" Invalid Vehicle Type!"<< endl;
            }
            
        }
       
    }
    file.close();
}



}

};
int main()
{

    FileHandler f1;
    f1.createFile("vehicles.txt");
    f1.readData("vehicles.txt");
  
 return 0;
}