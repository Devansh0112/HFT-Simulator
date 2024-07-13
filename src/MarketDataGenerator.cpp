#include "MarketDataGenerator.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

void MarketDataGenerator::generateMarketData(const std::string& filename, int interval_ms)
{
    std::ofstream file(filename);
    file << "timestamp,symbol,price,volume\n";

    const std::string symbols[] = {"AAPL", "GOOG", "MSFT"};
    const double prices[] = {145.32, 2732.45, 289.67};
    const int volumes[] = {100, 50, 75};

    auto start = std::chrono::system_clock::now();

    for(int i=0; i<1000; ++i)
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        int index = i % 3;
        file << now_c << "," << symbols[index] <<","<<prices[index] << volumes[index] << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }

    file.close();
}