#pragma once
#include <vector>
#include <string>
#include "../model/Sample.h"

class SampleGenerator {
public:
    std::vector<Sample> generate() const;
    void writeTo(const std::string& filePath) const;

private:
    static std::string toLine(const Sample& s);
};
