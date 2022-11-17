#include "sum_integers.hpp"
#include <vector>
double sum_integers(const std::vector<double> integers) {
    double sum = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}

int sum_integers(const std::vector<int> integers) {
    int sum = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}