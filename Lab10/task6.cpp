#include<iostream>
#include<fstream>
using namespace std;

class InventorySystem {

    int itemID;
    char itemName[20];

    public:
    InventorySystem(){
    itemID =0;
    for(int i=0; i<20 ; i++){
    itemName[i]= ' ';
    }
}
    InventorySystem(int itemID, char itemName[20]): itemID(itemID){
        for(int i=0; i<20 ; i++){
        this->itemName[i]= itemName[i];
        }
    
    }

    void saveData(string filename){
        
        ofstream writeFile(filename, ios::binary);
        if(writeFile.is_open()){
            writeFile.write((char*)&itemID, sizeof(itemID));
            writeFile.write(itemName, sizeof(itemName));
            writeFile.close();

        }
        else{
            cerr<< "Unable to open file "<< filename << " " << endl;
        }
    }

    void readData(string filename){
    
        ifstream readFile(filename, ios::in);
        if(readFile.is_open()){
            readFile.read((char*)&itemID, sizeof(itemID));

       readFile.read(itemName, sizeof(itemName));
            readFile.close();
            cout<< "Item ID: "<< itemID<< endl;
            cout<< "Item Name: "<< itemName<< endl;
        }
        else{
            cerr<< "Unable to open file "<< filename << " " << endl;
        }

    }


};
int main()
{
    char arr[]= {'F', 'r', 'a', 'g', 'r', 'a', 'n', 'c', 'e', '\0'};

    InventorySystem i1(24, arr);
    i1.saveData("inventory.dat");

    InventorySystem i2;
    i2.readData("inventory.dat");


  
 return 0;
}