#include "sum_integers.hpp"
#include <vector>
double sum_integers(const std::vector<double> integers) {
    double sum = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}

double average_integers(const std::vector<int> integers) {
    double sun = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum / static_cast<double>(integers.size());

int sum_integers(const std::vector<int> integers) {
    int sum = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}
