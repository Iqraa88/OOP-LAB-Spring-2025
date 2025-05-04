#include<iostream>
#include<fstream>

using namespace std;

class FileHandling{

    public:

    void createFile(string filename){
    
    ofstream file (filename);
    if(file.is_open()){
        file<<"Record 1\n";
        file<<"Record 2\n";
        file<<"Record 3\n";
        file<<"Record 4\n";
    file.close();
    
    }
    else{
    cerr<<"Unable to open file "<< filename<< " "<< endl;
    }
    
    }
    void skipFile(string filename){
    
        ifstream file(filename);
        if(file.is_open()){
        
            streampos position =20;

            file.seekg(position, ios::beg);

            string line;
            getline(file, line);
            cout<< "Record: "<< line << endl;
           
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
    f1.createFile("data_records.txt");
    f1.skipFile("data_records.txt");
  


 return 0;

}