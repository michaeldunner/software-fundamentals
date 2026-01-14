#include <iostream>

class BankAccount {
    public: BankAccount(std::string name, double balance){
        accountName = name;
        accountBalance = balance;
    }
    public: void setName(std::string name){
        accountName = name;
    }
    public: std::string getName(){
        return accountName;
    }

    public: void setBalance(double balance){
        accountBalance = balance;
    }
    public: double getBalance(){
        return accountBalance;
    }

    private: std::string accountName;
    private: double accountBalance;
};