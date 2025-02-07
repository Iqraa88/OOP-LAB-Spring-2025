#include<iostream>
using namespace std;

struct Product{
	string productID;
	string name;
	float quantity;
	float price;
	float totalPrice;
};
int main(){
	
	int noOfProd;
	float value=0;
	cout<<" How many products do you want to add? "<< endl;
	cin>> noOfProd;
	
	Product* p1= new Product[noOfProd];
	
	for(int i=0; i<noOfProd; i++){
		cin.ignore();
		cout<<"---------------------------------------"<< endl;
		cout<< "Enter ID of Product "<< i+1 << " : "<< endl;
		getline(cin, p1[i].productID);
		
		cout<< "Enter Name of Product "<< i+1 << " : "<< endl;
		getline(cin, p1[i].name);
		
		cout<< "Enter Quantity of Product "<< i+1 << " : "<< endl;
		cin>> p1[i].quantity;
		
		cout<< "Enter Price of Product "<< i+1 << " : "<< endl;
		cin>> p1[i].price;
		
		p1[i].totalPrice= p1[i].quantity* p1[i].price;
		 value+= p1[i].totalPrice;
	}
	
	cout<< "-----------------------------------------------------"<<endl;
	cout<< "The Inventory is currently of " << value << "$ worth."<< endl;
	
	delete[] p1;
	
	
	return 0;
}
