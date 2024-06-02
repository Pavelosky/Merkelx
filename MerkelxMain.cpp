#include "MerkelxMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelxMain::MerkelxMain(){

}

void MerkelxMain::init(){
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
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
    for (std::string const p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, "2020/03/17 17:01:30.099017");

        std::cout << "Asks: " << entries.size() << std::endl;

        std::cout << "Highest ask price: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Lowest ask price: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "Market looks good. " << std::endl;
    // std::cout << "Order book contains " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;  
    // unsigned int asks = 0;
    // for (OrderBookEntry& obe : orders)
    // {
    //     if (obe.orderType == OrderBookType::bid)
    //     {
    //         bids++;
    //     }
    //     if (obe.orderType == OrderBookType::ask)
    //     {
    //         asks++;
    //     }
    // }

    // std::cout << "There are " << bids << " bids and " << asks << " asks. " << std::endl;
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