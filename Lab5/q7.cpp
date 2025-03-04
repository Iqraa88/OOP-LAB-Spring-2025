#include<iostream>
#include<string.h>
#define max_products 10
using namespace std;


class Product{

    string ID;
    string name;
    int quantity;

    public:
    Product(string ID, string name, int quantity): ID(ID), name(name), quantity(quantity)
    {}

    string getName(){return name;}
    string getID(){return ID;}
    int getQt(){return  quantity;}

};

class Inventory{

    Product *products[max_products];
    int count;

    public:
    Inventory(int count =0): count(count){}

    void addProducts(Product *product){
        if(count< max_products){
            products[count]= product;
            count++;
        }
        else{
            cout<<"Inventory Full!"<< endl;
        }
    }

    void sortProducts(){
        for(int i=0; i<count-1; i++){
            for(int j=0; j<count-i-1; j++){
                if(products[j]->getName()> products[j+1]->getName()){
                    Product *temp= products[j];
                    products[j]= products[j+1];
                    products[j+1]= temp;
                   
                }
            }
        }
    }

    void displayProducts(){
      
        for(int i=0; i<count; i++){
            cout<<"---------------------------------"<< endl;
            cout<<"Name:"<< products[i]->getName()<< " "<< endl;
            cout<<"ID:"<< products[i]->getID()<< " "<< endl;
            cout<<"Quantity:"<< products[i]->getQt()<< " "<< endl;
                }
                cout<<"-----------------------------"<< endl;
    }

    void searchProduct(string ID){
        bool found=false;
        for(int i=0; i<count; i++){
            if(products[i]->getID()== ID){
                cout<<"The Product You Searched For is: "<< endl;
                cout<<"---------------------------------------------"<< endl;
                cout<<" Product Name: "<< products[i]->getName()<< " "<< endl;
                cout<<" Product ID: "<< products[i]->getID()<< " "<< endl;
                cout<<" Product Quantity: "<< products[i]->getQt()<< " "<< endl;
                cout<<"---------------------------------------------------"<< endl;
                 found= true;
            }

        }
        if(!found){
            cout<<" Product with ID: "<< ID<< " not found."<< endl;
        }

    }

   



};

int main()
{

    Product p1("PP22", "HP Laptop", 200);
    Product p2("00F3", "Earbuds", 100);
    Product p3("FK57", "Power Bank", 50);
    Product p4("HM22", "LED Lights", 300);
    Product p5("TA00", "USB Cable", 150);

    Inventory fastInventory;
    fastInventory.addProducts(&p1);
    fastInventory.addProducts(&p2);
    fastInventory.addProducts(&p3);
    fastInventory.addProducts(&p4);
    fastInventory.addProducts(&p5);

    cout<<" Displaying Products in Inventory:"<< endl;
    fastInventory.displayProducts();

    fastInventory.sortProducts();
    cout<<" Displaying Products in Inventory After Sorting:"<< endl;
    fastInventory.displayProducts();

    fastInventory.searchProduct("00F3");

  
 return 0;
};