#include<iostream>
using namespace std;


int **memoryAllocation(int rows, int cols){
	int** ptr= new int*[rows];
	for(int i=0;i<rows;i++){
		ptr[i]= new int[cols];
		
	}
	return ptr;
}

void arrayInput(int**ptr, int rows, int cols, int matrix){
	cout<< "------------------------------------"<< endl;
	cout<< "For Matrix "<< matrix << " : "<< endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<<" Enter element for row "<< i+1 << " and column "<< j+1 << " : "<< endl;
			cin>> *(*(ptr+i)+j);
		}
	}
}

void displayMatrix(int **ptr, int rows, int cols){
	cout<< "-------------------------------------------------"<< endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<< *(*(ptr+i)+j) << "  ";
		}
		cout<< endl;
	}
}

void deleteMemory(int **ptr, int rows){
	for(int i=0; i<rows; i++){
		delete[] ptr[i];
	}
	delete[] ptr;
	
	cout<< "Memory Cleared for Matrix! "<< endl;
	cout<< "--------------------------------------"<< endl;
}

int main(){
	
	int r1,r2,c1,c2;
	
	cout<< "Enter rows for matrix 1 : "<< endl;
	cin>> r1;	
	
	cout<< "Enter columns for matrix 1 : "<< endl;
	cin>> c1;
	
	int** ptr1= memoryAllocation(r1,c1);
		arrayInput(ptr1,r1,c1, 1);	
		
	cout<< "Enter rows for matrix 2 : "<< endl;
	cin>> r2;	
		
	cout<< "Enter columns for matrix 2 : "<< endl;
	cin>> c2;
	
	int **ptr2= memoryAllocation(r2,c2);
	
	arrayInput(ptr2,r2,c2, 2);	
			
	if(c1==r2){
		int **result= memoryAllocation(r1,c2);
		for(int i=0; i<r1; i++){
			for(int j=0; j<c2; j++){
				*(*(result+i)+j)=0;
			for(int k=0; k<c1;k++){
					*(*(result+i)+j)+= 	*(*(ptr1+i)+k)  *  *(*(ptr2+k)+j);
			}
			}
		}
		cout<< "The resultant matrix is : "<< endl;
		displayMatrix(result, r1, c2);
		
		deleteMemory(result, r1);
	}
	else{
		cout<< "Multiplication is not possible for the entered dimensions. "<< endl;
	}	
		
		deleteMemory(ptr1, r1);
		deleteMemory(ptr2, r2);
	
	

	return 0;
}
