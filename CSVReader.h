#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader{
    public:
        CSVReader();
        static std::vector<OrderBookEntry> readCSV(std::string CSVfile); // (1)
        static std::vector<std::string> tokenise(std::string csvLine, char separator); // (2)

        static OrderBookEntry stringsToOBE(std::string price,
                                           std::string amount,
                                           std::string timestamp,
                                           std::string product,
                                           OrderBookType orderBookType);
    private:
        static OrderBookEntry stringsToOBE(std::vector<std::string> string); // (3)
};