#include "MarketDataGenerator.hpp"
#include "MarketDataFeedHandler.hpp"
#include <iostream>

int main() {
    MarketDataGenerator generator;
    generator.generateMarketData("market_data.csv", 1000);

    MarketDataFeedHandler handler;
    handler.getMarketData("market_data.csv");

    for(const auto& data: handler.getMarketData("AAPL")) {
        std::cout << "Timestamp: " << data.timestamp << ", Symbol: " << data.symbol << ", Price: " << data.price << ", Volume: " << data.volume << std::endl;
    }
    return 0;
}