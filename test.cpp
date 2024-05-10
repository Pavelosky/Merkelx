#include <string> // Include the necessary header for std::string
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator){
    std::vector<std::string> tokens;

    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do{
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end){
            break;
        }
        if(end >= 0) 
            token = csvLine.substr(start, end - start);
        else 
            token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(csvLine.substr(start, end - start));

        start = end + 1;
    } while (end != std::string::npos);

    return tokens;
};

int main(){
    // 
    // std::string s = "2020/03/17 17:01:24.884492,BTC/USDT,ask,5405.41766912,0.69895055";

    // tokens = tokenise(s, ',');
    // for (std::string& token : tokens){
    //     std::cout << token << std::endl;
    // }

    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open()){
        while (std::getline(csvFile, line)){
            tokens = tokenise(line, ',');

            if (tokens.size() != 5){
                std::cout << "Bad line " << line << std::endl;
                continue;
            }
            double price = std::stod(tokens[3]);
            double amount = std::stod(tokens[4]);
            std::cout << "Price: " << price << " Amount: " << amount << std::endl;

            for (std::string& token : tokens){
                std::cout << token << std::endl;
            }
        }
        std::cout << "File opened successfully" << std::endl;
        csvFile.close();

    } else {
        std::cout << "Error opening file" << std::endl;
    }

    return 0;
}