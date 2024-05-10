#include "OrderBookEntry.h" // Include the header file for the OrderBookEntry class

OrderBookEntry::OrderBookEntry( double _price, 
                                double _amount, 
                                std::string _timestamp, 
                                std::string _product, 
                                OrderBookType _orderType)
: price(_price), 
amount(_amount), 
timestamp(_timestamp), 
product(_product), 
orderType(_orderType)
{

}