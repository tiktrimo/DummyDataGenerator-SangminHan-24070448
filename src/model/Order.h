#pragma once
#include <string>

enum class OrderStatus { RESERVED, REJECTED, PRODUCING, CONFIRMED, RELEASE };

inline std::string orderStatusToString(OrderStatus s) {
    switch (s) {
    case OrderStatus::RESERVED:  return "RESERVED";
    case OrderStatus::REJECTED:  return "REJECTED";
    case OrderStatus::PRODUCING: return "PRODUCING";
    case OrderStatus::CONFIRMED: return "CONFIRMED";
    case OrderStatus::RELEASE:   return "RELEASE";
    default:                     return "UNKNOWN";
    }
}

struct Order {
    std::string orderId;
    std::string sampleId;
    std::string customerName;
    int quantity = 0;
    OrderStatus status = OrderStatus::RESERVED;
};
