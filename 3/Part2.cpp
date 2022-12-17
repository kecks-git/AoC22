#include "input.h"
#include <iostream>
#include <vector>

using namespace std;

vector<string> split;

class Rucksack : public Base {
public:
  void update(const std::string &line) override { rucksacks.push_back(line); }

  int addAllCommonLetters() {
    for (int i = 0; i < rucksacks.size() - 2; i += 3) {
      increaseResultByPriorityValue(findCommonLetter(rucksacks, i));
    }
    return m_total;
  }

  char findCommonLetter(const vector<string> rs, const int index) {
    for (auto &i : rs.at(0 + index)) {
      if (rs.at(1 + index).find(i) != string::npos &&
          rs.at(2 + index).find(i) != string::npos)
        return i;
    }
    throw;
  }
  // increaseResultByPriorityValue(m_total, res);
  void increaseResultByPriorityValue(char res) {
    cout << res << endl;
    if (res >= 'A' && res <= 'Z')
      res -= (66 - 28);
    else if (res >= 'a' && res <= 'z')
      res -= (97 - 1);
    m_total += res;
    cout << (int)res << endl;
  }
  vector<string> rucksacks{};
  int m_total{};
};
int main() {
  Rucksack rs{};
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/3/input", rs);

  cout << rs.addAllCommonLetters() << endl;
  return 0;
}
