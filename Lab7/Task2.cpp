#include<iostream>
using namespace std;

class Product{

    protected:
    string productID;
    string productName;
    float price;
    int stockQuantity;

    public:
    Product(){}

    Product(string productID, string productName, float price, int stockQuantity): productID(productID), productName(productName), price(price), stockQuantity(stockQuantity){}

    virtual void displayInfo() {

        cout<< "------------------"<< endl;
        cout<< "Product ID: "<< productID<< " "<< endl;
        cout<< "Product Name: "<< productName<< " "<< endl;
        cout<< "Product Price: "<< price<< " "<< endl;
        cout<< "Product Qt: "<< stockQuantity<< " "<< endl;

    }

    virtual void applyDiscount(){
        price= 0.95*price; // FOR A 5% Disocunt
    }

    virtual float calculateTotalPrice(){
        return price*stockQuantity;
    }

    Product operator+(Product& p){
        Product temp;
        temp.price= price+ p.price;
        return temp;
    }



    friend ostream& operator<<(ostream &os, Product& p){
        os<< "--------------------------------"<< endl;
        os<< "Product ID: "<< p.productID<< " "<< endl;
        os<< "Product Name: "<< p.productName<< " "<< endl;
        os<< "Product Price: "<< p.price<< " "<< endl;
        os<< "Product Qt: "<< p.stockQuantity<< " "<< endl;

    }
                                                  
    float getPrice(){return price;}

};
 
class Electronics: public Product{

    string warrantyPeriod;
    string brand;

    public:

    Electronics(string productID, string productName, float price, int stockQuantity, string warrantyPeriod, string brand): Product(productID, productName, price, stockQuantity), warrantyPeriod(warrantyPeriod), brand(brand){}

    void displayInfo()override{

        Product::displayInfo();
        cout<< "Warranty Period: "<< warrantyPeriod<< " "<< endl;
        cout<< "Brand: "<< brand<< " "<< endl;

    }

};

    class Clothing: public Product{
        int size;
        string color;
        string fabricMaterial;

        public:
        Clothing(string productID, string productName, float price, int stockQuantity, int size, string color, string fabricMaterial): Product(productID, productName, price, stockQuantity), size(size), color(color), fabricMaterial(fabricMaterial){}

        void applyDiscount()override{
            price= 0.5*price;

        }
    
        
    };

    class FoodItem: public Product{

        string expiryDate;
        double calories;

        public:
        FoodItem(string productID, string productName, float price, int stockQuantity, string expiryDate, double calories): Product(productID, productName, price, stockQuantity), expiryDate(expiryDate), calories(calories){}

        float calculateTotalPrice() override{

            price= stockQuantity* price;
            if(stockQuantity> 5){price= 0.95*price;}
            return price;
        }
    };
    class Book: public Product{

        string author, genre;

        public:
        Book(string productID, string productName, float price, int stockQuantity, string author, string genre): Product(productID, productName, price, stockQuantity), author(author), genre(genre){}

        void displayInfo()override{
            Product::displayInfo();

            cout<<" Author: "<< author << " "<< endl;
            cout<<" Genre: "<< genre << " "<< endl;
        }
    };
int main()
{

    Product *ptr;
    Electronics e1("201P", "Smartphone", 85000, 10, "24Months" , "Samsung");

    ptr= &e1;
    ptr->displayInfo();
    
    Clothing c1("C301", "T-Shirt", 1200.5, 15, 'L', "Blue", "Cotton");
    ptr= &c1;
    ptr->applyDiscount();
    cout<< c1;

    FoodItem f1("4F01", "Oreo Biscuits", 350.0, 2200, "12-10-2025", 100);

    ptr= &f1;
    ptr->calculateTotalPrice();
    cout<< f1;

    Book b1("501B", "Atomic Habits", 850.0, 10,  "James Clear", "Self-help");

    ptr= &b1;
    ptr->displayInfo();

    cout<<"----------------------"<< endl;
    
    
    Product sum= e1+c1;
    cout<< "Combined Price is: "<< sum.getPrice()<< " ."<< endl;




  
     
 return 0;
}