#include <iostream>
#include <windows.h>
#include "src/generator/SampleGenerator.h"
#include "src/generator/OrderGenerator.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    const std::string samplesPath = "data/samples.dat";
    const std::string ordersPath  = "data/orders.dat";
    const int         orderCount  = 20;

    SampleGenerator sampleGen;
    OrderGenerator  orderGen(42);  // seed=42 for reproducible output

    // Generate and write samples
    sampleGen.writeTo(samplesPath);
    auto samples = sampleGen.generate();

    std::vector<std::string> sampleIds;
    for (const auto& s : samples) sampleIds.push_back(s.id);

    // Generate and write orders
    orderGen.writeTo(ordersPath, orderCount, sampleIds);
    auto orders = orderGen.generate(orderCount, sampleIds);

    // Summary output
    std::cout << "=== DummyDataGenerator POC ===\n\n";
    std::cout << "[생성 완료]\n";
    std::cout << "  시료 : " << samples.size() << "종  -> " << samplesPath << "\n";
    std::cout << "  주문 : " << orders.size()  << "건  -> " << ordersPath  << "\n\n";

    std::cout << "[생성된 시료 목록]\n";
    for (const auto& s : samples) {
        std::cout << "  " << s.id << " | " << s.name
                  << " | yield:" << s.yield
                  << " | stock:" << s.stock << "ea\n";
    }

    std::cout << "\n[생성된 주문 샘플 (첫 5건)]\n";
    for (int i = 0; i < 5 && i < static_cast<int>(orders.size()); ++i) {
        const auto& o = orders[i];
        std::cout << "  " << o.orderId
                  << " | " << o.sampleId
                  << " | " << o.customerName
                  << " | " << o.quantity << "ea"
                  << " | " << orderStatusToString(o.status) << "\n";
    }

    return 0;
}
