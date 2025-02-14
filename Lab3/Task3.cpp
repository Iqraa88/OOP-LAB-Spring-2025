#include<iostream>
using namespace std;

class Library{

string bookList[100];
string borrowedBooks[100];
string availableBooks[100];
int count;
int isAvailable[100];
int borrowCount;

public:

Library(){
    count=0;
    borrowCount=0;
}

void addBooks(int noOfBooks){
        cout<< "------------------------------------"<< endl;

    if(noOfBooks>0){
         cin.ignore();
    for(int i=0; i<noOfBooks; i++){
       
        cout<< "Enter Name of Book "<< i+1 << " :"<< endl;
        getline(cin,bookList[i]);
        isAvailable[i]=1;
        availableBooks[i]= bookList[i];
        count++;
        
    }
    }
    else{
        cout<< "Please enter valid number of Books! "<< endl;
    }
}

void borrowBooks(int indexofBook){
        cout<< "------------------------------------"<< endl;

    if(indexofBook>=0 && indexofBook < count){
    if(isAvailable[indexofBook]){
       borrowedBooks[borrowCount]= bookList[indexofBook];
 
       isAvailable[indexofBook]=0;
        cout<< "You have successfully borrowed "<< borrowedBooks[borrowCount] << " Book!"<< endl;
       borrowCount++;

      
    }
    else{
        cout<< "This Book is already Borrowed!"<< endl;
    }
    }
    else{
        cout<< "Enter valid index!"<< endl;
    }
}

void available(){
    cout<< "------------------------------------"<< endl;
    cout<< "Available Books are: "<< endl;
    for(int i=0; i<count ;i++){
        if(isAvailable[i]){
        cout<<" Book "<< i+1<< "  :"<< availableBooks[i]<< endl;
    }
    }
}


void returnBooks(int indexBr){
        cout<< "------------------------------------"<< endl;


 
if(indexBr>=0 && indexBr< borrowCount){
    if(!isAvailable[indexBr] && borrowedBooks[indexBr]== bookList[indexBr]){
        borrowCount--;
        isAvailable[indexBr]=1;
        borrowedBooks[indexBr]=" ";
        cout<<"You have returned "<< bookList[indexBr]<< " Book!"<< endl;

    }
    else{
         cout<<"The Book is already Available!" << endl;

    }
}
else{
    cout<< "Please! Enter Valid(starting from 0) Index!"<< endl;
}

}


};

int main(){

    int numBooks, index;
    cout<<" How many books do you want to add?"<< endl;
    cin>> numBooks;

Library l1;
l1.addBooks(numBooks);
l1.available();

cout<<"Enter Index of  book you want to borrow?"<< endl;
    cin>> index;
l1.borrowBooks(index);
l1.available();


cout<<"Enter Index of  book you want to return?"<< endl;
    cin>> index;
l1.returnBooks(index);
l1.available();

    return 0;
}
