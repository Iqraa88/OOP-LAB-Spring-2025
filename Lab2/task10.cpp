#include<iostream>
using namespace std;

int main(){
	
	int d1,d2,d3;

	cout<<" Enter the first dimension for array: "<<endl;
	cin>> d1;
	cout<<" Enter the second dimension for array: "<<endl;
	cin>> d2;
	cout<<" Enter the third dimension for array: "<<endl;
	cin>> d3;
	
	int***ptr = new int**[d1];
	for(int i=0; i<d1; i++){
		ptr[i]= new int*[d2];
		for(int j=0; j<d2; j++){
			ptr[i][j]= new int[d3];
		}
	}
	
	for(int i=0; i<d1; i++){
		for(int j=0;  j<d2; j++){
			for(int k=0; k<d3; k++){
				cout<< "Enter element at index "<< i+1 << j+1 << k+1 << endl;
				cin>> ptr[i][j][k];
			}
		}
	}
	
	cout<<" The 3-D Array is:  "<< endl;
	cout<< "-------------------------------"<< endl;
		for(int i=0; i<d1; i++){
		for(int j=0;  j<d2; j++){
			for(int k=0; k<d3; k++){
				cout<< ptr[i][j][k]<< "  ";
				
			}
			cout<< endl;
			
		}
		cout<< endl;
	}
	
	for(int i=0; i<d1; i++){
		for(int j=0; j<d2; j++){
			delete[] ptr[i][j];
		}
		delete[] ptr[i];
	}

	delete[] ptr;
	
	return 0;
}
