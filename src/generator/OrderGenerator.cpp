#include "OrderGenerator.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

static const std::vector<std::string> CUSTOMERS = {
    "삼성전자 파운드리", "SK하이닉스", "LG이노텍",
    "DB하이텍", "네패스", "앰코테크", "한미반도체", "이오테크닉스"
};

static const std::vector<OrderStatus> STATUSES = {
    OrderStatus::RESERVED, OrderStatus::PRODUCING,
    OrderStatus::CONFIRMED, OrderStatus::RELEASE, OrderStatus::REJECTED
};

OrderGenerator::OrderGenerator(int seed) : seed_(seed) {}

int OrderGenerator::nextRand() const {
    seed_ = (seed_ * 1103515245 + 12345) & 0x7fffffff;
    return seed_;
}

std::string OrderGenerator::generateOrderId(int seq) const {
    std::time_t t = std::time(nullptr);
    std::tm tm{};
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << "ORD-" << std::put_time(&tm, "%Y%m%d")
        << "-" << std::setw(4) << std::setfill('0') << seq;
    return oss.str();
}

std::string OrderGenerator::toLine(const Order& o) {
    return o.orderId + "|" + o.sampleId + "|" + o.customerName + "|" +
           std::to_string(o.quantity) + "|" + orderStatusToString(o.status);
}

std::vector<Order> OrderGenerator::generate(int count,
    const std::vector<std::string>& sampleIds) const {
    std::vector<Order> orders;
    for (int i = 1; i <= count; ++i) {
        Order o;
        o.orderId      = generateOrderId(i);
        o.sampleId     = sampleIds[nextRand() % sampleIds.size()];
        o.customerName = CUSTOMERS[nextRand() % CUSTOMERS.size()];
        o.quantity     = (nextRand() % 490) + 10;  // 10 ~ 499
        o.status       = STATUSES[nextRand() % STATUSES.size()];
        orders.push_back(o);
    }
    return orders;
}

void OrderGenerator::writeTo(const std::string& filePath, int count,
    const std::vector<std::string>& sampleIds) const {
    std::ofstream f(filePath);
    for (const auto& o : generate(count, sampleIds)) f << toLine(o) << "\n";
}
