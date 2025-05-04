#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class FileHandling{

public:
void UpdatingPosition(string filename){

    ofstream file(filename, ios::out);
    if(file.is_open()){
        file<< "AAAAA";
        file<< "BBBBB";
        file<< "CCCCC";

        file.close();
        cout<<"-------------------------"<< endl;
        cout<< "Content written to file successfully! "<< endl;
        readFile(filename);


    }
    else{
        cerr<< "Unable to open file "<< filename << " " << endl;
    }

     fstream reOpen(filename, ios::out | ios::in);
    if(reOpen.is_open()){
     reOpen.seekp(5);
     reOpen<<"XXXXX";
     reOpen.close();

     cout<<"-------------------------"<< endl;
     cout<<"File updated successfully!"<< endl;
     readFile(filename);
     
    
    }

    else{
        cerr<< "Unable to open file "<< filename << " " << endl;

    }

}

void readFile(string filename){

ifstream file(filename, ios::in);
if(file.is_open()){
    string line;
    while(getline(file, line)){
         cout<<line <<endl;
    }

    file.close();

}

else{
    cerr<<" Unable to load file "<< filename<< " "<< endl;
}

}


};
int main()
{

    FileHandling f1;
    f1.UpdatingPosition("config.txt");
  
 return 0;
}