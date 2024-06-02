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
};