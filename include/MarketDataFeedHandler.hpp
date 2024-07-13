#ifndef MARKET_DATA_HANDLER_HPP
#define MARKET_DATA_HANDLER_HPP

#include<string>
#include<vector>
#include<unordered_map>
#include<ctime>

struct MarketData {
    std::time_t timestamp;
    std::string symbol;
    double price;
    int volume;
};

class MarketDataFeedHandler {
private:
    std::unordered_map<std::string, std::vector<MarketData>> marketData;
public:
    void processmarketdData(const std::string& filename);
    const std::vector<MarketData>& getMarketData(const std::string& symbol) const;
};

#endif