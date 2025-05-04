#include<iostream>
#include<fstream>
using namespace std;

class FileHandling{

public:

void createFile(string filename){
    
    ofstream file (filename);
    if(file.is_open()){
        file<<"This is the first part of the log.\n";
        file<<"This is the second part of the log.\n";
        file<<"And the third part.\n";
        
    file.close();
    
    }
    else{
    cerr<<"Unable to open file "<< filename<< " "<< endl;
    }
    
    }
void readPosition(string filename){

    ifstream file(filename, ios::in);
    if(file.is_open()){
    
        string line;
        while(getline(file,line)){
        streampos position= file.tellg();
        cout<<line<< endl;
        cout<<"Current Position: "<< position<< " "<< endl;

        }

        file.close();
    }

    else{
        cerr<<"Error: Unable to open file "<< filename<< " "<< endl;
    }

}



};

int main()

{

    FileHandling f1;
    f1.readPosition("large_log.txt");
 return 0;
}