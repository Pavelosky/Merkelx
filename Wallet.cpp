#include "Wallet.h"
#include "CSVReader.h"

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

    bool Wallet::canFulfillOrder(OrderBookEntry order){

        std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
        //ask
        if (order.orderType == OrderBookType::ask){
            double amount = order.amount;
            std::string currency = currs[0];
            std::cout << "Wallet::canFulfillOrder: " << currency << " " << amount << std::endl;
            return containsCurrency(currency, amount);
        }
        //bid
        if(order.orderType == OrderBookType::bid){
            double amount = order.amount * order.price;
            std::string currency = currs[1]; 
            return containsCurrency(currency, amount);
        }
        return false;
    }
            
void Wallet::processSale(OrderBookEntry& sale){
    //process a sale and update the wallet
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
    //ask
    if (sale.orderType == OrderBookType::asksale){
        //outgoing currency
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        //incoming currency
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1]; 

        currencies[outgoingCurrency] -= outgoingAmount;
        currencies[incomingCurrency] += incomingAmount;
    }
    //bid
    if(sale.orderType == OrderBookType::bidsale){
        //outgoing currency
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];
        //incoming currency
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0]; 

        currencies[outgoingCurrency] -= outgoingAmount;
        currencies[incomingCurrency] += incomingAmount;
    }
}