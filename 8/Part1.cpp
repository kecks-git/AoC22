#include "input.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

Grid<int> calculateVisibility(Grid<char> &grid) {
  Grid<int> visible;
  for (int y = 0; y < grid.y_width; ++y) {
    for (int x = 0; x < grid.x_width; ++x) {
      visible.data.push_back(0);
    }
  }
  visible.x_width = grid.x_width;
  visible.y_width = grid.y_width;
  for (auto &i : visible.data) {
    i = 0;
  }
  int max1 = 0;
  int max2 = 0;
  int max3 = 0;
  int max4 = 0;
  for (int y = 0; y < grid.y_width; ++y) {
    max1 = 0;
    max2 = 0;
    max3 = 0;
    max4 = 0;
    for (int x = 0; x < grid.x_width; ++x) {
      auto point = Point{x, y};
      if (grid.get(point) > max1) {
        max1 = grid.get(point);
        visible.set(point, visible.get(point) + 1);
      }
      point = Point{y, x};
      if (grid.get(point) > max2) {
        max2 = grid.get(point);
        visible.set(point, visible.get(point) + 1);
      }
      point = Point{y, grid.x_width - x - 1};
      if (grid.get(point) > max3) {
        max3 = grid.get(point);
        visible.set(point, visible.get(point) + 1);
      }
      point = Point{grid.x_width - x - 1, y};
      if (grid.get(point) > max4) {
        max4 = grid.get(point);
        visible.set(point, visible.get(point) + 1);
      }
    }
  }
  return visible;
}

int main() {
  // Read the data
  auto grid = readLineByLine("/home/stephan/Dev/AoC/8/input");
  auto Result = calculateVisibility(grid);
  cout << count_if(Result.data.begin(), Result.data.end(), [=](int i) {
    return i >= 1;
  }) << endl;
  cout << reduce(Result.data.begin(), Result.data.end()) << endl;

  // Part 2
  return 0;
}
