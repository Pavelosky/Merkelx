#pragma once // Include guard to prevent multiple inclusion of the same header file
#include <string> // Include the necessary header for std::string

enum class OrderBookType {bid, ask, unknown};

// this is the correct way to create a class in C++
class OrderBookEntry{
    public:
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
        
        static OrderBookType stringToOrderBookType(std::string s);

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;

        static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2){
            return e1.timestamp < e2.timestamp;
        }
        
        static bool compareByPriceAsc(const OrderBookEntry& e1, const OrderBookEntry& e2){
            return e1.price < e2.price;
        }

        static bool compareByPriceDesc(const OrderBookEntry& e1, const OrderBookEntry& e2){
            return e1.price > e2.price;
        }
};