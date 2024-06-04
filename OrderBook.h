#pragma once 

#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook{    
    public:
    /**construct , reding a csv file*/
        OrderBook(std::string filename);
        /**get all known products*/
        std::vector<std::string> getKnownProducts();
        /**get the Orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

        /** returns the earliest time in the orderbook*/
        std::string getEarliestTime();
        /** returns the next time after the sent time in the orderbook
         * if there is no next tiomestamp it wraps around to the first timestamp in the orderbook
        */
        std::string getNextTime(std::string timestamp);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
    
        

    private:
        std::vector<OrderBookEntry> orders;
};