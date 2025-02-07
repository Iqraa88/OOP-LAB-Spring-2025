#include<iostream>

using namespace std;

int main(){
	
	int row1,cols1,row2,cols2;
	
	cout<<" Enter Rows for first matrix: "<< endl;
	cin>> row1;
	
	cout<<" Enter Columns for first matrix: "<< endl;
	cin>> cols1;
	
	int** ptr1= new int*[row1];
	for(int i=0; i<row1; i++){
		ptr1[i]= new int[cols1];
	}
	
	cout<<" Memory Allocated for Matrix1!"<< endl;
	cout<< endl;
	
	cout<<" Enter rows for secomd matrix: "<< endl;
	cin>> row2;
	
	cout<<" Enter rows for second matrix: "<< endl;
	cin>> cols2;
	
	int** ptr2 = new int*[row2];
	for(int i=0; i<row2; i++){
		ptr2[i]= new int[cols2];
	}
		cout<<" Memory Allocated for Matrix2!"<< endl;
	
	for(int i=0; i<row1; i++){
		for(int j=0; j<cols1; j++){
			cout<<" Enter element for row " << i+1 << " & column " << j+1 << " of Matrix1: "<< endl;
			cin>> ptr1[i][j];
		}
	}
	
	for(int i=0; i<row2; i++){
		for(int j=0; j<cols2; j++){
			cout<<" Enter element for row " << i+1 << " & column " << j+1 << " of Matrix2: "<< endl;
			cin>> ptr2[i][j];
		}
	}
	
	
	
	if(row1== row2 && cols1==cols2 ){
		
		// MEMORY FOR ADD MATRIX
		int** add= new int*[row1];
	for(int i=0; i<row1; i++){
		add[i]= new int[cols1];
	}
	
	// MEMORY FOR SUB MATRIX
		int** sub= new int*[row1];
	for(int i=0; i<row1; i++){
		sub[i]= new int[cols1];
	}
	
	for(int i=0; i<row1; i++){
		for(int j=0; j<cols1; j++){
			 add[i][j]= ptr1[i][j]+ ptr2[i][j];
			 sub[i][j]= ptr1[i][j]- ptr2[i][j];
		}
	
	}
	
		cout<< "----------------------------------------"<< endl;
	for(int i=0; i<row1; i++){
		for(int j=0; j<cols1; j++){
			
			 cout<< add[i][j] << "  ";
		}
		cout<< endl;
	}
	
	cout<< "----------------------------------------"<< endl;
	for(int i=0; i<row1; i++){
		for(int j=0; j<cols1; j++){
			 cout<< sub[i][j] << "  ";
		}
		cout<< endl;
	}
	
	
for(int i=0; i<row1; i++){
	delete[] add[i];
}
delete[] add;


for(int i=0; i<row1; i++){
	delete[] sub[i];
}
delete[] sub;
	
}
else{
	cout<<" Addition/Subtraction is not possible since the dimensions are different."<< endl;
}

for(int i=0; i<row1; i++){
	delete[] ptr1[i];
}
delete[] ptr1;


for(int i=0; i<row2; i++){
	delete[] ptr2[i];
}
delete[] ptr2;
	
	
	return 0;
}
