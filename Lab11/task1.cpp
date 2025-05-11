#include<iostream>
#include<stdexcept>
#include<sstream>


using namespace std;

class DimensionExceptionClass: public exception{

    string message;
public:

DimensionExceptionClass(int r1, int c1, int r2, int c2){

     ostringstream oss;
        oss << " Dimension Exception - Matrices must have same dimensions (" 
            << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")!";
        message = oss.str();

}
const char* what(){

    return message.c_str();

}
};

template<class T>
class Matrix{

    int r,c;
    T** matrix;

    public:
    Matrix(int r, int c): r(r), c(c){
    
        matrix= new T*[r];
        for(int i=0; i<r; i++){
        matrix[i]= new T[c];
        }
    
    }

    void input(){
    
        for(int i=0; i<r; i++){
        for(int j=0 ;j<c; j++){
        
            cout<< "Enter element for row "<< i<< " and column "<< j<< " : "<< endl;
            cin>> matrix[i][j];

        }
        }
    
    }

    void display(){
    for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
    cout<<matrix[i][j]<<"   ";
    }
    cout<<endl;
    }
    }

    Matrix<T> operator+(const Matrix<T>& other){
        if(this->r!=other.r || this->c!= other.c){
            throw DimensionExceptionClass(r, c, other.r, other.c);
        }
        else{
            
            Matrix<T> resultMat(r,c);
            for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                
                resultMat.matrix[i][j]= matrix[i][j]+ other.matrix[i][j];

            }
            }
            return resultMat;


        }
    }

    

};
int main()
{

    
    try{
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);
    
    Matrix<int> m3(2,2);
    Matrix<int> m4(3,3);
    
    m1.input();
    m2.input();

    Matrix<int>result= m1+m2;
    cout<<"---------------------------"<<endl;
    result.display();

    m3.input();
    m4.input();

      Matrix<int>result2= m3+m4;
    cout<<"---------------------------"<<endl;
    result2.display();

    }
    catch( DimensionExceptionClass &e){
    
        cout<<e.what();
    }
  
 return 0;
}
