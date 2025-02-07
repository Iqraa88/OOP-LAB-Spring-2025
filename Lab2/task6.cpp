#include<iostream>
#include<string.h>

using namespace std;

struct Student{
	string name;
	string rollNum;
	float marks[3];
	float avg;
};


int main(){

	
	int noOfStd;
	
	cout<<" How many students you want to add? "<< endl;
	cin>> noOfStd;

	
	
	 Student* std= new Student[noOfStd];
	 

	 for(int i=0; i<noOfStd; i++){
	 	cin.ignore();
	 	cout<< "Enter the name of Student "<< i+1 << " : "<< endl;
	 	getline(cin, std[i].name );
	 	
	 	cout<< "What's the Roll-Number of Student  "<< i+1 << " : "<< endl;
	 	getline(cin, std[i].rollNum);
	 	for(int j=0; j<3; j++){
	
	 	cout<< "Subject "<< j+1 << " Marks for Student "<< i+1 << " : "<< endl;
	 	cin>> std[i].marks[j];
	 	
	 	 std[i].avg+= std[i].marks[j];
	 }
	 std[i].avg= std[i].avg/3;
	 }
	 
	  for(int i=0; i<noOfStd; i++){
	  	cout<< "---------------------------------------"<< endl;
	  	
	 	cout<< "Name of Student "<< i+1 << " : "<< std[i].name << endl;
	
	 	cout<< "Roll Number of Student "<< i+1 << " : "<< std[i].rollNum << endl;
	 		for(int j=0; j<3; j++){
	
	 	cout<< "Subject "<< j+1 << " Marks for Student "<< i+1 << " : "<< std[i].marks[j] << endl;
	 }

	 	cout<< "Average"<< i+1 << " : "<< std[i].avg << endl;
	 	
	 	 
}
	 
	 delete[] std;
	 
	 cout<< "Thankyou! Allocated Memory Cleared."<< endl;
	 
	 
	
	
	return 0;
}
