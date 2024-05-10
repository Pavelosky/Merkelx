#pragma once // Include guard to prevent multiple inclusion of the same header file
#include <string> // Include the necessary header for std::string

enum class OrderBookType { bid, offer };

// this is the correct way to create a class in C++
class OrderBookEntry{
    public:
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
        // Remove the unnecessary opening brace here
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};