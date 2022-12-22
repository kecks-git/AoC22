#include "input.h"
#include "tube.h"
#include <gtest/gtest.h>

TEST(Day10, readInput) {
  auto input = readInput("/home/stephan/Dev/AoC/9/example");
  EXPECT_GE(input.size(), 1);
}

TEST(Day10, getSignalStrength) {
  Tube tube{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
  const std::vector<int> input{0, 1, 2};
  llint res = 6;
  EXPECT_EQ(tube.getSignalStrength(input), res);
}

TEST(Day10, iterate) {
  Tube tube{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
  const std::vector<int> input{0, 1, 2};
  llint res = 6;
  EXPECT_EQ(tube.getSignalStrength(input), res);
}
