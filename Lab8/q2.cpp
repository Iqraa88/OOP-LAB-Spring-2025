#include<iostream>
using namespace std;


class Account{
    int accNum;
    double balance;

    friend class Manager;
    friend void transferFunds(Account &acc1, Account &acc2, double amount);

    public:
    Account(int accNum, double balance): accNum(accNum), balance(balance){} 
    

};
class Manager{

    public:

    void displayDetails(Account &Acc )const{
        
        cout<< "---------------------------------------------"<< endl;
        cout<< " | Displaying Details | "<< endl;
        cout<< " | Account Number: "<< Acc.accNum << " | "<< endl;
        cout<< " | Total Balance: "<< Acc.balance << " | "<< endl;
        cout<< "---------------------------------------------"<< endl;

    }

    void updateBalance( Account &Acc, string action, double amount){
        if(action== "Withdraw" && amount>0 && amount<= Acc.balance){
            Acc.balance-= amount;
            cout<< " Amount : "<< amount << " withdrawn successfully!"<< endl;
        }
    
            else if(action== "Deposit" && amount>0 ){
                Acc.balance+= amount;
                cout<< " Amount : "<< amount << " deposited successfully!"<< endl;
            }
            else{
                cout<< " Invalid Action!"<< endl;
            }
        }
    
};

void transferFunds(Account &acc1, Account &acc2, double amount){
    if(amount >0 && amount<= acc1.balance){
        acc2.balance+= amount;
        acc1.balance-= amount;
        cout<<" Amount: "<< amount<< " Trasferred from Account holding - "<< acc1.accNum << " to Account holding - "<< acc2.accNum << " !"<< endl;
    }
    else{
        cout<< "Insufficient Amount!"<< endl;
    }

}

int main()

{

    Account NayaPay(24000199, 10000);
    Account EasyPaisa(0333311, 5000);
    Manager I;

    I.displayDetails(NayaPay);
    I.displayDetails(EasyPaisa);

    I.updateBalance(NayaPay, "Withdraw", 2000);
    I.updateBalance(EasyPaisa, "Deposit", 3000 );

    transferFunds(NayaPay, EasyPaisa, 5000);

    I.displayDetails(NayaPay);
    I.displayDetails(EasyPaisa);

  
 return 0;

}