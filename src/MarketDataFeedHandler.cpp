#include "MarketDataFeedHandler.hpp"
#include <fstream>
#include <sstream>

void MarketDataFeedHandler::processmarketdData(const std::string& filename) {
    std::fstream file(filename);
    std::string line;
    std::getline(file, line);

    while(std::getline(file, line)) {
        std::istringstream ss(line);
        MarketData data;
        std::string token;

        std::getline(ss, token, ',');
        data.timestamp = std::stol(token);
        std::getline(ss, token, ',');
        data.symbol = token;
        std::getline(ss, token, ',');
        data.price = std::stod(token);
        std::getline(ss, token, ',');
        data.volume = std::stoi(token);

        marketData[data.symbol].push_back(data);
    }
}