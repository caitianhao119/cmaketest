#include "sum.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> integers;
    for (auto i = 1; i < argc; i++) {
        integers.push_back(std::stoi(argv[i]));
    }
    auto res = sum(integers);
    std::cout << res << std::endl;
}