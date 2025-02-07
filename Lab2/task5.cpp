#include<iostream>
using namespace std;

int main(){
	int numInt,sum=0;
	cout<<" How many integers you want to add? "<< endl;
	cin>> numInt;
	
	int *ptr= new int[numInt];
	
	for(int i=0; i<numInt; i++){
		cout<< "Enter integer "<< i+1 << " : "<< endl;
		cin>> ptr[i];
	}
	cout<< "The Array is : "<< endl;
	for(int i=0; i<numInt; i++){
	
		cout<< *(ptr+i)<< "  ";
	}
	
	for(int i=0; i<numInt; i++){
		sum+= *(ptr+i);
	}
	cout<< endl;
	cout<< "The Sum of Array Elements is: "<< sum << endl;
	
	delete[] ptr;

	
	return 0;
}
