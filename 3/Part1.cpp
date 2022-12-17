#include "input.h"
#include <iostream>
#include <vector>

using namespace std;

vector<string> split;

class Rucksack : public Base {
public:
  void update(const std::string &line) override {
    auto res = findSameCharInEqualSubstring(line);
    increaseResultByPriorityValue(m_total, res);
  }
  char findSameCharInEqualSubstring(const std::string &line) {
    auto firstCompartment = line.substr(0, line.size() / 2);
    auto secondCompartment = line.substr(line.size() / 2, line.size() - 1);
    cout << firstCompartment << " " << secondCompartment << endl;
    for (auto &i : firstCompartment) {
      if (secondCompartment.find(i) != string::npos) {
        cout << i << endl;
        return i;
      }
    }
    return 0;
  }
  void increaseResultByPriorityValue(int &m_total, char res) {
    cout << res << endl;
    if (res >= 'A' && res <= 'Z')
      res -= (66 - 28);
    else if (res >= 'a' && res <= 'z')
      res -= (97 - 1);
    m_total += res;
    cout << (int)res << endl;
  }
  int m_total{};
};
int main() {

  cout << rs.m_total << endl;
  return 0;
}
