#include<iostream>
#include<string.h>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;

};



int main(){

    

int numOfBooks;
cout<<" How many books you want to input?"<< endl;
cin>> numOfBooks;

Book* books= new Book[numOfBooks];

for(int i=0; i<numOfBooks; i++){
	cin.ignore();
	    cout<< "-------------------------------------------"<< endl;
    cout<<"Enter Book "<< i+1 << " Title: "<< endl;
   getline( cin , books[i].title);

     cout<<"Enter Book "<< i+1 << "AuthorName: "<< endl;
    getline (cin, books[i].author);

     cout<<"Enter Book "<< i+1 << "Publishing Year: "<< endl;
    cin>> books[i].year;
}


cout<<"The following books were published after 2020."<< endl;

for(int i=0; i<numOfBooks; i++){
cout<< "--------------------------------------------------"<<endl;

if(books[i].year> 2020){
    cout<<"Book "<< i+1 << " Title: "<< books[i].title <<  endl;
     cout<<" Book "<< i+1 << "AuthorName: "<< books[i].author<<  endl;
     cout<<"Enter Book "<< i+1 << "Publishing Year: "<< books[i].year << endl;

}


}

delete[]books;



cout<<"Thankyou. The memory has been cleared."<< endl;
    


return 0;

}
