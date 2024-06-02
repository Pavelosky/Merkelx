#pragma once

#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelxMain{
    public:
        MerkelxMain();
        /** Call this to start the sim */
        void init();
    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();    
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption); 

        OrderBook orderBook{"20200317.csv"};
};