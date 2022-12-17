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
    if (line.back() == 'X')
      mine = 1;
    else if (line.back() == 'Y')
      mine = 2;
    else if (line.back() == 'Z')
      mine = 3;
    if (line.at(0) == 'A')
      theirs = 1;
    else if (line.at(0) == 'B')
      theirs = 2;
    else if (line.at(0) == 'C')
      theirs = 3;

    // Rock paper siccors logic
    if (mine == theirs)
      total += 3;
    else if (mine - theirs == 1 or mine - theirs == -2)
      total += 6;

    total += mine;
  };
  vector<string> m_Food{};
  double total;
};

int main() {
  None none;
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/2/input", none);

  cout << none.total << endl;
  return 0;
}
