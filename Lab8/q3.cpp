#include<iostream>
using namespace std;

class Vector2D{
    double x;
    double y;

    friend int dotProduct( Vector2D &v1, Vector2D &v2);

    public:
    Vector2D(){
        x=0;
        y=0;
    }
    Vector2D(double x, double y): x(x), y(y){}

    Vector2D operator+( Vector2D &v1){
        Vector2D v;
        v.x= this->x + v1.x;
        v.y= this->y + v1.y;
        return v;
    }

    Vector2D operator-( Vector2D &v1){
        Vector2D v;
        v.x= this->x - v1.x;
        v.y= this->y - v1.y;
        return v;
    }

    Vector2D operator*( int scalar){
        Vector2D v;
        
        v.x= this->x * scalar;
        v.y= this->y * scalar ;
        return v;
    }

   friend ostream& operator<<(ostream& os, const Vector2D& v);

};

int dotProduct(Vector2D &v1, Vector2D &v2){

    return (v1.x*v2.x + v1.y*v2.y);

}

ostream& operator<<(ostream& os, const Vector2D& v){

    os<< "Vector: ( "<<v.x << " , "<< v.y << " )"<< endl;
    return os; 
}

int main()
{
  
    Vector2D vectorOne(2,3);
    Vector2D vectorTwo(8,2);
    Vector2D add;

    cout<< "Vector Addition"<< endl;
    add= vectorOne+ vectorTwo;
    cout<< add;

    Vector2D subt;
    cout<< "Vector Subtraction"<< endl;
    subt = (vectorOne- vectorTwo);
    cout<< subt;

    Vector2D mult;
    cout<< "Vector- Scalar Multiplication "<< endl;
    mult= vectorOne* 4;
    cout<< mult;
    
    cout<< "The Dot Product of the vectors is: "<< dotProduct(vectorOne, vectorTwo)<< " ."<< endl;


 return 0;

}