#include <iostream>
#include <vector>
#include <string> // Include the necessary header for std::string
#include "OrderBookEntry.h"
#include "MerkelxMain.h"
#include "CSVReader.h"
#include "Wallet.h"
    
int main()
{   
    // std::cout << "Hello, welcome to our trading app. " << std::endl;
    // MerkelxMain app{};
    // app.init();
    
    // return 0;
    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("ETH", 5);
    std::cout << "Wallet has: " << wallet.toString() << std::endl;
    wallet.removeCurrency("BTC", 5);
    std::cout << "Wallet has: " << wallet.toString() << std::endl;
}

