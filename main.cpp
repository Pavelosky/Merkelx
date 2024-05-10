#include <iostream>
#include <vector>
#include <string> // Include the necessary header for std::string
#include "OrderBookEntry.h"
#include "MerkelxMain.h"
    
int main()
{   
    std::cout << "Hello, welcome to our trading app. " << std::endl;
        MerkelxMain app{};
        app.init();
        
        return 0;
    }
