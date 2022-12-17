#include "input.h"
#include <iostream>
#include <vector>

using namespace std;

class None : public Base {
public:
  void update(const std::string &line) override {
    m_Food.push_back(line);
    int mine{};
    int theirs{};
    // X loose
    // y draw
    // Z win
    // A rock
    // B paper
    // C scissor
    if (line.back() == 'X') {
      if (line.at(0) == 'A')
        total += 3;
      else if (line.at(0) == 'B')
        total += 1;
      else if (line.at(0) == 'C')
        total += 2;
    } else if (line.back() == 'Y') {
      if (line.at(0) == 'A')
        total += 1;
      else if (line.at(0) == 'B')
        total += 2;
      else if (line.at(0) == 'C')
        total += 3;
      total += 3;
    } else if (line.back() == 'Z') {
      total += 6;
      if (line.at(0) == 'A')
        total += 2;
      else if (line.at(0) == 'B')
        total += 3;
      else if (line.at(0) == 'C')
        total += 1;
    }
  }
  vector<string> m_Food{};
  double total;
};

int main() {
  None none;
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/2/input", none);

  cout << none.total << endl;
  return 0;
}
