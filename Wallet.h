#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "OrderBookEntry.h"

class Wallet{
    public:
        Wallet();
        /**insert currency to the wallet*/
        void insertCurrency(std::string type, double amount);

        /**remove currency from the wallet */
        bool removeCurrency(std::string type, double amount);

        /**check if the wallet contains this much currency*/
        bool containsCurrency(std::string type, double amount);

        /**check if the wallet can fulfill an order*/
        bool canFulfillOrder(OrderBookEntry order);

        /**generate a string representation of the wallet*/
        std::string toString();
        
    private:
        std::map<std::string, double> currencies;
};