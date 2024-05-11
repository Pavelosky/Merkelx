#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader{
    public:
        CSVReader();
        static std::vector<OrderBookEntry> readCSV(std::string CSVfile); // (1)
    private:
        static std::vector<std::string> tokenise(std::string csvLine, char separator); // (2)
        static OrderBookEntry stringsToOBE(std::vector<std::string> string); // (3)
};