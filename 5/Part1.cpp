#include "input.h"
#include <assert.h>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void reverse(stack<char> &in) {
  char item;
  stack<char> tmpStack;

  while (in.empty() == false) {
    item = in.top();
    in.pop();
    tmpStack.push(item);
  }
  swap(tmpStack, in);
  return;
}

class Crane : public Base {
public:
  void update(const string &line) override {
    if (not finished) {
      if (line.at(1) == '1') {
        finished = true;
        for (auto &i : stacks) {
          reverse(i);
          cout << i.top() << endl;
        }
        return;
      }
      for (auto it = line.begin(); it != line.end(); it++) {
        if (*it == '[') {

          stacks.at((it - line.begin()) / 4).push(*(it + 1));
        }
      }
      return;
    } else {
      if (line.size() >= 6) {
        int nr = (int)(line.at(5)) - 48;
        int from{};
        int to{};

        if (line.at(6) != ' ') {
          nr *= 10;
          nr += (int)(line.at(6) - 48);
          from = (int)(line.at(13) - 48 - 1);
        } else {
          from = (int)(line.at(12) - 48 - 1);
        }
        to = line.back() - 48 - 1;
        cout << nr << " from " << from << " to " << to << endl;
        // Part 2
        stack<char> temp{};
        for (int i = 0; i < nr; ++i) {
          // Part 1
          /*
          stacks.at(to).push(stacks.at(from).top());
          stacks.at(from).pop();*/
          // Part 2
          temp.push(stacks.at(from).top());
          stacks.at(from).pop();
        }
        // Part 2
        while (not temp.empty()) {
          stacks.at(to).push(temp.top());
          temp.pop();
        }
        assert(nr < 50);
      }
    }
  }
  int m_total{};
  bool finished{false};
  vector<stack<char>> stacks{};
};

int main() {
  Crane cr{};
  // Read the data
  while (cr.stacks.size() != 9)
    cr.stacks.push_back(stack<char>{});
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/5/input", cr);
  for (auto &i : cr.stacks) {
    cout << i.top();
  }
  cout << endl;
  return 0;
}
