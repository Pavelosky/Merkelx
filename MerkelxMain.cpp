#include "MerkelxMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <limits>

MerkelxMain::MerkelxMain(){

}

void MerkelxMain::init(){
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 5);

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
    std::cout << "3: Make an Ask " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;

    std::cout << "Current time: " << currentTime << std::endl;
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
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::vector<OrderBookEntry> bids = orderBook.getOrders(OrderBookType::bid, p, currentTime);

        std::cout << "Asks: " << entries.size() << std::endl;
        std::cout << "Bids: " << bids.size() << std::endl;

        std::cout << "Highest ask price: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Lowest ask price: " << OrderBook::getLowPrice(entries) << std::endl;
        std::cout << "========================================== "  << std::endl;

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

// This function needs to be fixed it seems that it asks for input twice. Changes made tot his function were in the video in week 8 "Making it robust"
void MerkelxMain::enterAsk()
{
    std::cout << "Make an Ask - enter the amount: product,price,amount, eg. ETH/BTC,200,0.5 " << std::endl;
    std::string input;
    
    std::getline(std::cin, input);
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3){
        std::cout << "Bad input " << input << std::endl;
    }
    else{
        try{
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
            orderBook.insertOrder(obe);
        }
        catch (const std::exception& e){
            std::cout << "MerkelxMain::enter Ask Bad input " << input << std::endl;
        }
    }
    std::cout << "You entered: " << input << std::endl;
}

void MerkelxMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product,price,amount, eg. ETH/BTC,200,0.5 " << std::endl;
    std::string input;

    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3){
        std::cout << "Bad input " << input << std::endl;
    }
    else{
        try{
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
            orderBook.insertOrder(obe);
        }
        catch (const std::exception& e){
            std::cout << "MerkelxMain::enter Bid Bad input " << input << std::endl;
        }
    }
    std::cout << "You entered: " << input << std::endl;
}

void MerkelxMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
    std::cout << "You have: " << wallet.toString() << " BTC" << std::endl;
}
        
void MerkelxMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry& sale : sales)
    {
        std::cout << "Sale price: " << sale.price << " || Sale amount: " << sale.amount << " || Sale time: " << sale.timestamp << std::endl;
    }
    currentTime = orderBook.getNextTime(currentTime);
}
 
int MerkelxMain::getUserOption()
{
    int userOption = 0;

    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);
    }
    catch (const std::exception& e){

    }
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
        enterAsk();
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