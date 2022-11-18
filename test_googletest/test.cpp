#include "sum_integers.hpp"
#include "gtest/gtest.h"
#include <vector>
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(example, sum_zero) {
  std::vector<double> integers = {1, -1, 2, -2, 3, -3};
  auto result = sum_integers(integers);
  ASSERT_EQ(result, 0);
}

TEST(example, sum_five) {
  std::vector<double> integers = {1, 2, 3, 4, 5};
  auto result = sum_integers(integers);
  ASSERT_EQ(result, 15);
}

TEST(example, sum_double) {
  std::vector<double> integers = {1.2, 2.4, 3.6, 4.8, 5.0};
  auto result = sum_integers(integers);
  ASSERT_EQ(result, 17.0);
}