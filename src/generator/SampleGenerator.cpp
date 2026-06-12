#include "SampleGenerator.h"
#include <fstream>

std::vector<Sample> SampleGenerator::generate() const {
    return {
        {"S-001", "실리콘 웨이퍼-8인치",   0.5, 0.92, 480},
        {"S-002", "GaN 에피택셜-4인치",    0.3, 0.78, 220},
        {"S-003", "SiC 파워기판-6인치",    0.8, 0.92,  30},
        {"S-004", "포토레지스트-PR7",      0.2, 0.95, 910},
        {"S-005", "산화막 웨이퍼-SiO2",    0.6, 0.88,   0},
        {"S-006", "질화막 웨이퍼-Si3N4",   0.7, 0.85, 150},
        {"S-007", "InP 기판-2인치",        1.2, 0.70,  45},
        {"S-008", "다이아몬드 기판",        2.0, 0.60,  10},
    };
}

std::string SampleGenerator::toLine(const Sample& s) {
    return s.id + "|" + s.name + "|" +
           std::to_string(s.avgProductionTimeMin) + "|" +
           std::to_string(s.yield) + "|" +
           std::to_string(s.stock);
}

void SampleGenerator::writeTo(const std::string& filePath) const {
    std::ofstream f(filePath);
    for (const auto& s : generate()) f << toLine(s) << "\n";
}
