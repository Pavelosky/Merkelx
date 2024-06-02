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

    for (OrderBookEntry& e : orders){
        if (e.orderType == type && e.product == product && e.timestamp == timestamp){
            orders_sub.push_back(e);
        }
    }

    return orders_sub;
};

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders){
    double max = orders[0].price;
    for (OrderBookEntry& e : orders){
        if (e.price > max){
            max = e.price;
        }
    }
    return max;
};


double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders){
    double low = orders[0].price;
    for (OrderBookEntry& e : orders){
        if (e.price < low){
            low = e.price;
        }
    }
    return low;
};
