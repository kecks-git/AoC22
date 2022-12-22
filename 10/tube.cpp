#include "tube.h"
#include "input.h"
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using llint = long long int;

llint Tube::getSignalStrength(const vector<int> &indices) {

  std::vector<llint> result;
  result.reserve(indices.size());

  for (auto index : indices) {
    if (index >= 0 && index < static_cast<int>(signalStrength.size())) {
      result.push_back(index * signalStrength[index - 1]);
      cout << index << " " << signalStrength[index - 1] << endl;
    }
  }
  return std::accumulate(result.begin(), result.end(), 0);
}

void Tube::iterate(std::optional<llint> add) {
  if (add.has_value()) {
    signalStrength.push_back(currentValue);
    signalStrength.push_back(currentValue);
    currentValue += add.value();
  } else
    signalStrength.push_back(currentValue);
}

void Tube::drawScreen() {
  vector<llint> screen;
  screen.reserve(240);
  for (llint i = 0; i < static_cast<llint>(signalStrength.size()); ++i) {
    if (i % 40 == signalStrength[i] or i % 40 == signalStrength[i] + 1 or
        i % 40 == signalStrength[i] - 1)
      cout << "#";
    else
      cout << ".";
    if (i % 40 == 39)
      cout << endl;
  }
  cout << endl;
}
