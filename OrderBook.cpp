#include <map>
#include "OrderBook.h"
#include "CSVReader.h"
#include <algorithm>
#include "OrderBookEntry.h"


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

std::string OrderBook::getEarliestTime(){
    return orders[0].timestamp;
};

std::string OrderBook::getNextTime(std::string timestamp){

    std::string next_timestamp = "";
    for(OrderBookEntry& e : orders){
        if (e.timestamp > timestamp){
            next_timestamp = e.timestamp;
            break;
        }
    }
    if(next_timestamp == ""){
        next_timestamp = orders[0].timestamp;
    }
    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order){
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp){
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    
    std::vector<OrderBookEntry> sales;

    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    
    for (OrderBookEntry& a : asks){
        for (OrderBookEntry& b : bids){
            if (b.price >= a.price){
                
                OrderBookEntry sale{a.price, 0, timestamp, product, OrderBookType::asksale};

                if (b.username == "simuser" ){
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;

                if (a.username == "simuser" ){
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::asksale;
                }

                if(b.amount == a.amount){
                    sale.amount = a.amount;
                    sales.push_back(sale);
                    b.amount = 0;
                }
                if(b.amount > a.amount){
                    sale.amount = a.amount;
                    sales.push_back(sale);
                    b.amount -= a.amount;
                    break;
                }
                if(b.amount < a.amount){
                    sale.amount = b.amount;
                    sales.push_back(sale);
                    a.amount -= b.amount;
                    b.amount = 0;
                    continue;
                }
                }
            }
        }
        return sales;
    }
};