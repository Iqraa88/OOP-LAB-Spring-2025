#include<iostream>
using namespace std;

class Student{

    string ID;
    string name;
    int *examScores;
    int count;

    public:
    
    Student(string name, string ID, int count, int *scs): name(name), ID(ID), count(count), examScores(scs){
        examScores= new int[count];

        for(int i=0; i<count; i++){
            examScores[i]= scs[i];
        }

    }

    

    Student(const Student &obj){
        ID= obj.ID;
        name= obj.name;
        count= obj.count;
        examScores= new int[obj.count];
        for(int i=0; i<count; i++){
            examScores[i]= obj.examScores[i];
        }
    }

    void displayStudent(){
        cout<<"----------------------------------------"<< endl;
        cout<<"Name: "<< name<< " "<< endl;
        cout<<"Student ID: "<< ID<< " "<< endl;
        for(int i=0; i<count; i++){
        cout<<"----------------------------------------"<< endl;
        cout<<"Score  "<< i+1 << " "<< examScores[i]<< " "<< endl;
    }
         cout<<"----------------------------------------"<< endl;

}

    ~ Student(){
        delete [] examScores;
        cout<< "DELETING ARRAY!"<< endl;
    }


};

int main()
{

    int arr[3]= {45, 77, 61};

    Student s1("abcdef", "24K-1024", 3, arr);
    cout<< "Displaying Student Details: "<< endl;
    s1.displayStudent();
    
    Student duplicate(s1);
    cout<< "Verifying Details: "<< endl;
    duplicate.displayStudent();

  
 return 0;
}