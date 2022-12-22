#include "input.h"
#include "tube.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
  auto lines = readInput("/home/stephan/Dev/AoC/10/input");
  Tube tube{{}};

  for (auto &line : lines) {
    std::optional<int> opt{};
    auto val = splitStrings(line, ' ');
    if (val.size() == 2)
      opt = stoi(val.at(1));
    tube.iterate(opt);
  }
  cout << tube.getSignalStrength({{20, 60, 100, 140, 180, 220}}) << endl;

  tube.drawScreen();

  return 0;
}
