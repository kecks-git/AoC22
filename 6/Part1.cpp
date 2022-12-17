#include "input.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool hasDuplicate(string::const_iterator it, int n) {
  string input{it, it + n};
  cout << input << endl;
  sort(input.begin(), input.end());
  return unique(input.begin(), input.end()) != input.end();
}

int subStringUnequal(const string &s, int n) {
  for (auto it = s.begin(); it != s.end() - n + 1; it++) {
    if (not hasDuplicate(it, n))
      return it - s.begin() + n;
  }
  return 0;
}

class MyString : public Base {
public:
  void update(const string &line) override { input = line; }
  string input{};
};

int main() {
  MyString myString{};
  // Read the data
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/6/input", myString);
  // Part 2: 14 instead of 4
  cout << subStringUnequal(myString.input, 4) << endl;
  return 0;
}
