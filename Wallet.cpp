#include "Wallet.h"

Wallet::Wallet(){
    //initialize the wallet with 0 currency
}
    void Wallet::insertCurrency(std::string type, double amount){
        //insert the currency to the wallet
        double balance = 0;
        if (amount < 0){
            throw std::invalid_argument("Amount cannot be negative");
        }

        if(currencies.count(type) == 0){  //if the currency is not in the wallet
            balance = 0;
        }
        else{
            balance = currencies[type]; //if the currency is in the wallet
        }
        balance += amount;
        currencies[type] = balance;
    }


    bool Wallet::containsCurrency(std::string type, double amount){
        //check if the wallet contains this much currency
        if (currencies.count(type) == 0){
            return false;
        }
        else{
            return currencies[type] >= amount;
        }
    }

    std::string Wallet::toString(){
        //generate a string representation of the wallet
        return "";
    }
