#include<iostream>
using namespace std;

int main(){
	
	int size;
	
	cout<<" Enter the size of Array: "<< endl;
	cin>> size;
	
	int** ptr= new int*[size];
	for(int i=0; i<size; i++){
		ptr[i]= new int;
	}
	
	for(int i=0; i<size; i++){
		cout<<" Enter the element for index "<< i << " : "<<endl;
		cin>> *(*(ptr+i));
	}
	cout<<"---------------------------------"<<endl;
	
	for(int i=0; i<size; i++){
		cout<< *(*(ptr+i))<< "  ";
	}
	
	for(int i=0; i<size; i++){
		delete[] ptr[i];
	}
	delete[] ptr;

	return 0;
}
