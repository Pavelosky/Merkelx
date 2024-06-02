#include <map>
#include "OrderBook.h"
#include "CSVReader.h"

OrderBook::OrderBook(std::string filename){

    orders = CSVReader::readCSV(filename);

}

std::vector<std::string>  OrderBook::getKnownProducts(){
    std::vector<std::string> products;

    std::map<std::string, bool> prodMap;

    // Iterate through the orders and add each product to the prodMap
    for (OrderBookEntry& e : orders){
        prodMap[e.product] = true;
    }

    // Iterate through the prodMap and add each product to the products vector
    for (auto const& x : prodMap){
        products.push_back(x.first);
    }

    return products;
}

std::vector<OrderBookEntry>  OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp){
    std::vector<OrderBookEntry> orders_sub;
    return orders_sub;
};