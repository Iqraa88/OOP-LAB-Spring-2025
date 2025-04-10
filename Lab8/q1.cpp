#include<iostream>
#include<math.h>

using namespace std;


class Complex{

    double realPart;
    double imaginaryPart;

    friend double magnitude(Complex *c);

    public:

    Complex(){
        realPart=0;
        imaginaryPart= 0;
    }
    Complex(int realPart, int imaginaryPart): realPart(realPart), imaginaryPart(imaginaryPart){}

    Complex operator+(const Complex& obj){
        Complex c;
        c.realPart= realPart+ obj.realPart;
        c.imaginaryPart= imaginaryPart+ obj.imaginaryPart;
        return c;
    }

    Complex operator-(const Complex& obj){
        Complex c;
        c.realPart= realPart- obj.realPart;
        c.imaginaryPart= imaginaryPart-obj.imaginaryPart;
        return c;
    }

    Complex operator*(const Complex& obj){
        Complex c;
        c.realPart= realPart* obj.realPart- imaginaryPart*obj.imaginaryPart;
        c.imaginaryPart= realPart* obj.imaginaryPart + imaginaryPart* obj.realPart;
        return c;
    }

    Complex operator/(const Complex& obj){
        Complex c;
        int denominator= pow(obj.realPart,2) + pow(obj.imaginaryPart,2);
        c.realPart= (realPart* obj.realPart+ imaginaryPart*obj.imaginaryPart)/denominator;
        c.imaginaryPart= (imaginaryPart*obj.realPart - realPart*obj.imaginaryPart) /denominator;
        return c;
    }


     friend ostream& operator << ( ostream& os, const Complex& obj);
    
    

};

ostream& operator << ( ostream& os, const Complex& obj){
    os<< "The Complex Number is: "<< obj.realPart << " + "<< obj.imaginaryPart << " i"<< endl;
    return os;
}

double magnitude(Complex *c){

    return sqrt(pow(c->realPart,2)+ pow(c->imaginaryPart,2));
}

int main()
{

    Complex num1(2,3);
    Complex num2(4,1);
    Complex add;

    add= num1+num2;
    cout<< add;


    Complex sub= num1- num2;
    cout<< sub;

    Complex product= num1*num2;
    cout<< product;

    Complex div= num1/num2;
    cout<< div;

    cout<< "The magnitude of num1 is: " << magnitude(&num1)<< " "<< endl;;
    cout<< "The magnitude of num2 is: " << magnitude(&num2)<< " "<< endl;;



  
 return 0;
}
