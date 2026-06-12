#pragma once
#include <vector>
#include <string>
#include "../model/Order.h"

class OrderGenerator {
public:
    explicit OrderGenerator(int seed = 42);
    std::vector<Order> generate(int count, const std::vector<std::string>& sampleIds) const;
    void writeTo(const std::string& filePath,
                 int count,
                 const std::vector<std::string>& sampleIds) const;

private:
    mutable int seed_;
    int nextRand() const;
    std::string generateOrderId(int seq) const;
    static std::string toLine(const Order& o);
};
