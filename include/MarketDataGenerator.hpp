#ifndef MARKET_DATA_GENERATOR_HPP
#define MARKET_DATA_GENERATOR_HPP

#include<string>

class MarketDataGenerator {
public:
    void generateMarketData(const std::string& filename, int interval_ms);
};

#endif