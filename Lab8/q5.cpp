#include<iostream>
using namespace std;

class Matrix2x2{

    int a1;
    int a2;
    int a3;
    int a4;

    friend int calculateDeterminant(Matrix2x2 &m);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);

    public:

    Matrix2x2(){
        a1=0, a2=0; a3=0; a4=0;
    }

    Matrix2x2(int a1, int a2, int a3, int a4): a1(a1), a2(a2), a3(a3), a4(a4){}

    Matrix2x2 operator+(Matrix2x2& mat1){
        Matrix2x2 temp;
        temp.a1= a1+mat1.a1;
        temp.a2= a2+mat1.a2;
        temp.a3= a3+mat1.a3;
        temp.a4= a4+mat1.a4;
        return temp;
    }

    Matrix2x2 operator-(Matrix2x2& mat1){
        Matrix2x2 temp;
        temp.a1= a1-mat1.a1;
        temp.a2= a2-mat1.a2;
        temp.a3= a3-mat1.a3;
        temp.a4= a4-mat1.a4;
        return temp;
    }
    Matrix2x2 operator*(Matrix2x2& mat1){
        Matrix2x2 temp;
        temp.a1= a1*mat1.a1;
        temp.a2= a2*mat1.a2;
        temp.a3= a3*mat1.a3;
        temp.a4= a4*mat1.a4;
        return temp;
    }
};

class MatrixHelper{

    public:

    void updateMatrix(Matrix2x2 &m, string oldElement, int newElement){
        if(oldElement== "a1"){
            m.a1= newElement;
        }
        else if(oldElement== "a2"){
            m.a2= newElement;
        }
        else if(oldElement== "a3"){
            m.a3= newElement;
        }
        else if(oldElement== "a4"){
            m.a4= newElement;
        }
        else{
            cout<< "Invalid Old Element!"<< endl;
        }
    }
};

int calculateDeterminant(Matrix2x2 &m){
    return (m.a1*m.a4 - m.a2*m.a3);
}

ostream& operator<<(ostream& os, const Matrix2x2& m){
    os<< "[ "<< m.a1 << "  "<< m.a2 << " ]"<< endl;
    os<< "[ "<< m.a3 << "  "<< m.a4 << " ]"<< endl;
    return os;
}



int main()
{

    Matrix2x2 A(2,4,6,8);
    cout<< "Matrix A."<< endl;
    cout<< A;
    Matrix2x2 B(1,3,5,7);
    cout<< "Matrix B."<< endl;
    cout<< B;
    MatrixHelper help;

    Matrix2x2 add;
    add= A+B;
    cout<< "-------------------------------"<< endl;
    cout<< "Addition of Matrices."<< endl;
    cout<< add;

    Matrix2x2 sub;
    sub= A-B;
    cout<< "-------------------------------"<< endl;
    cout<< "Subtraction of Matrices."<< endl;
    cout<< sub;

    Matrix2x2 multiply;
    multiply= A*B;
    cout<< "-------------------------------"<< endl;
    cout<< "Multiplication of Matrices."<< endl;
    cout<< multiply;

    cout<< "Calculating Determinant For Matrix A..."<< endl;
    cout<< " Determinant is: "<< calculateDeterminant(A)<< " "<< endl;

    cout<< "Calculating Determinant For Matrix B..."<< endl;
    cout<< " Determinant is: "<< calculateDeterminant(B)<< " "<< endl;
  
    cout<< "Updating Matrix A..."<< endl;
    help.updateMatrix(A, "a4", 10);
    cout<< A;
    
 return 0;
}