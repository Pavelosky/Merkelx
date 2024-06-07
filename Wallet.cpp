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

    bool Wallet::removeCurrency(std::string type, double amount){
        //remove currency from the wallet
        if (amount < 0){    //amount cannot be negative
            return false;
        }

        if (currencies.count(type) == 0){ //if the currency is not in the wallet
            return false;
        }
        else{  // is there enough currency to remove?
            if(containsCurrency(type, amount)){ //there is enough
                std::cout << "Removing " << amount << " " << type << " from the wallet" << std::endl;
                currencies[type] -= amount;
                return true;
            }
            else{   //currency is there but there is not enough
                return false;
            }  
        }
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
        std::string s;
        for(std::pair<std::string, double> pair : currencies){
            std::string currency = pair.first;
            double amount = pair.second;
            s += currency + ": " + std::to_string(amount) + "\n";
        }
        return s;
    }
