#include<iostream>
#include<string.h>

using namespace std;

struct Employee{
	string name;
	float hoursWorked;
	float hourlyRate;
	float totalSalary;
};


int main(){
	
	int noOfEmp;
	
	cout<<" How many employees you want to add? "<< endl;
	cin>> noOfEmp;

	
	
	 Employee* emp= new Employee[noOfEmp];
	 

	 for(int i=0; i<noOfEmp; i++){
	 	cin.ignore();
	 	cout<< "Type the name of Employee "<< i+1 << " : "<< endl;
	 	getline(cin, emp[i].name);
	 	
	 	cout<< "How many hours does Employee "<< i+1 << " works?  "<< endl;
	 	cin>> emp[i].hoursWorked;
	 	
	 	cout<< "What's the hourly rate for Employee "<< i+1 << " : "<< endl;
	 	cin>> emp[i].hourlyRate;
	 	
	 	 emp[i].totalSalary= emp[i].hourlyRate * emp[i].hoursWorked;
	 	 
	 }
	 
	  for(int i=0; i<noOfEmp; i++){
	  	cout<< "---------------------------------------"<< endl;
	  	
	 	cout<< "Name of Employee "<< i+1 << " : "<< emp[i].name << endl;
	
	 	cout<< "Working Hours of Employee "<< i+1 << " : "<< emp[i].hoursWorked << endl;
	 	
	 	cout<< "Hourly rate of Employee "<< i+1 << " : "<< emp[i].hourlyRate << endl;
	 	
	 	cout<< "Total Salary of Employee "<< i+1 << " : "<< emp[i].totalSalary << endl;
	 	
	 	 
	 }
	 
	 delete[] emp;
	 
	 cout<< "Thankyou! Allocated Memory Cleared."<< endl;
	 
	 
	
	
	return 0;
}
