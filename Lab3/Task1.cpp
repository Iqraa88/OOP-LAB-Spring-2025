#include<iostream>
using namespace std;


class Wallet{

private:

string ownerName;
double totalBalance;
string transactionHistory[50];
int count;

void transactions(string message){
    if(count<50){
    transactionHistory[count++]= message;
    }
    else{
        cout<< " No more transactions can be stored!"<< endl;
    }
}

public:
 Wallet(){
    count=0;

    
 }

 void setName(string name){
    ownerName= name;
 }

 string getName(){
    return ownerName;
 }

void setTotalBalance(double balance){
    totalBalance= balance;
}

double getTotalBalance(){
    return totalBalance;
}

void addMoney(double money){
    totalBalance+= money;
    transactions("Added: " + to_string(money));
    
    
}

void spendMoney(double spend){
    if(spend> totalBalance){
        cout<< "Insufficient Balance!"<< endl;
        
    }
    else{
    totalBalance-= spend;
    transactions("Spent: "+ to_string(spend));
    
     
    
    }
}

void displayTransactionHistory(){
cout<<"Displaying Transaction History for "<< ownerName<< endl;
for(int i=0; i<count; i++){
    cout<< i+1 << "| "<< transactionHistory[i] <<" |"<< endl;
}
cout<< "------------------------------------------"<<endl;
cout<< "Your Total Balance: "<< totalBalance << endl;
cout<< "------------------------------------------"<<endl;

}

};

int main(){
Wallet w1;
w1.setName("Saad");
w1.setTotalBalance(0);
w1.addMoney(5000);
w1.spendMoney(500);
w1.displayTransactionHistory();


    return 0;
}
