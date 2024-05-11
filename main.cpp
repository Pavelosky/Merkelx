#include <iostream>
#include <vector>
#include <string> // Include the necessary header for std::string
#include "OrderBookEntry.h"
#include "MerkelxMain.h"
#include "CSVReader.h"
    
int main()
{   
    std::cout << "Hello, welcome to our trading app. " << std::endl;
        // MerkelxMain app{};
        // app.init();
        CSVReader::readCSV("20200317.csv");
        return 0;
    }

