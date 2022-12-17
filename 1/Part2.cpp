#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "input.h"

using namespace std;

class Food : public Base {
public:
  void update(const std::string &line) override {
    if (line.empty()) {
      m_Food.push_back(m_curFood);
      m_curFood = 0;
    } else
      m_curFood += stoi(line);
  };

  void print() {
    for (auto &i : m_Food)
      cout << i << endl;
  }
  vector<int> m_Food{};
  int m_curFood{};
};

int main() {

  Food food;
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/1/input", food);
  int Result{};
  for (int i = 0; i < 3; ++i) {
    auto it = max_element(food.m_Food.begin(), food.m_Food.end());
    cout << *it << endl;
    Result += *it;
    food.m_Food.erase(it);
  }
  cout << Result << endl;
  return 0;
}
