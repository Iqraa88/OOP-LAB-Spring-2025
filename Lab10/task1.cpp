#include<iostream>
#include<fstream>
using namespace std;

class FileHandler{

    public:

    void createFile(string filename){
    
        ofstream openFile (filename);
        if(openFile.is_open()){
          openFile<<"//Vehicle Database\n";
           openFile<< "AutonomousCar,AC101,RoboTaxi,2023,SM:4.5,CERT-AI\n";
            openFile<<"ElectricVehicle,EV202,VoltZ,2022,Battery:150,CERT-ECO\n";
           openFile<< "HybridTruck,HT303,GreenHauler,2021,Cargo:5000|Battery:75,CERT-HYBRID\n";
        openFile.close();
        
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
            cout<<data<<endl;
            cout<<endl;
        }
        file.close();
        
        }

        else{
            cerr<<"Unable to open file "<< filename<< " ."<< endl;
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
