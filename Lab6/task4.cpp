#include<iostream>
using namespace std;

class Account{

    int accountNumber;
    float balance;

    public:

    Account(int accountNumber, float balance): accountNumber(accountNumber), balance(balance){}


        void displayDetails(){
            cout<<"----------------------"<< endl;
            cout<< "Account Number: "<< accountNumber<< " "<< endl;
            cout<< "Balance: "<< balance<< " "<< endl;
        }
    
};

class CheckingAccount: public Account{

    float interestRate;

    public:
    CheckingAccount(int accountNumber, float balance, float interestRate): Account(accountNumber, balance), interestRate(interestRate){}

    void displayCheckingAccount(){
        Account::displayDetails();
        cout<<"Interest Rate: "<< interestRate<< " "<< endl;
        cout<<"------------------------"<< endl;
    }

};

class SavingsAccount: public Account{
    float overDraftLimit;

    public:
    SavingsAccount(int accountNumber, float balance, float overDraftLimit): Account(accountNumber, balance), overDraftLimit(overDraftLimit){}

    void displaySavingsAccount(){
        Account::displayDetails();
        cout<<"Over Draft Limit: "<< overDraftLimit<<" "<< endl;
        cout<<"------------------------"<< endl;
    }
};


int main()
{
    CheckingAccount c1(3456, 3000.00, 1.5);
    SavingsAccount s1(3456, 3000.00, 5000.00 );
    
    cout<<"Checking Account Details: "<< endl;
    c1.displayCheckingAccount();
    cout<< "Saving Account Details: "<< endl;
    s1.displaySavingsAccount();
  
 return 0;

}