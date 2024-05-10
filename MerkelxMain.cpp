#include "MerkelxMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
MerkelxMain::MerkelxMain(){

}

void MerkelxMain::init(){
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelxMain::loadOrderBook(){
    std::cout << "Loading order book. " << std::endl;

    orders.push_back(OrderBookEntry(5000.01, 0.001, "2021-01-01 00:00:00", "BTC/USDT", OrderBookType::bid));
    orders.push_back(OrderBookEntry(2001.01, 0.02, "2021-01-01 00:00:01", "BTC/USDT", OrderBookType::bid));

}

void MerkelxMain::printMenu(){
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void MerkelxMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void  MerkelxMain::printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
    std::cout << "Order book contains " << orders.size() << " entries" << std::endl;
}

void MerkelxMain::enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void MerkelxMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelxMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void MerkelxMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int MerkelxMain::getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelxMain::processUserOption(int userOption){

    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }       
}