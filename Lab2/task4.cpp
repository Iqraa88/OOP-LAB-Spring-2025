#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	int numStr;
	cout<<" How many strings you want to input? "<< endl;
	cin>> numStr;
	
	
	string* ptr= new string[numStr];
	
	cin.ignore();
	
		for(int i=0; i<numStr; i++){
		cout<< "Please Type String "<< i+1 << endl;
		getline(cin, ptr[i]);
	}
	
	for(int i=0; i<numStr-1; i++){
		for(int j=0; j<numStr-i-1; j++){
		
		if(ptr[j+1]<ptr[j]){
			string temp= ptr[j];
			ptr[j]= ptr[j+1];
			ptr[j+1]= temp;
		}	
		}
	}
		cout<< "---------------------------"<< endl;
		for(int i=0; i<numStr; i++){
		
		cout<< "|String " << i+1 << " | "<< " : " << " | " << ptr[i] << " | " <<endl;
		}
	
		cout<< "---------------------------"<< endl;
		
		delete[] ptr;
	
	return 0;
}
