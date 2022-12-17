#include "input.h"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Signals {
  string left;
  string right;
};

int numFromIterator(auto &iterator) {
  if (*(iterator + 1) == '0') {
    iterator += 2;
    return 10;
  } else {
    int num{*iterator - '0'};
    ++iterator;
    return num;
  }
}

int rightBiggerThanLeft(auto &leftSignal, auto &rightSignal, auto &leftEnd,
                        auto &rightEnd, int num) {
  while (leftSignal != leftEnd or rightSignal != rightEnd) {
    // cout << *leftSignal << " " << *rightSignal << endl;
    if (*leftSignal == '[' and *rightSignal == '[') {
      ++leftSignal;
      ++rightSignal;
    }
    if (*leftSignal == ',' and *rightSignal == ',') {
      ++leftSignal;
      ++rightSignal;
    }
    if (*leftSignal == ']' and *rightSignal == ']') {
      ++leftSignal;
      ++rightSignal;
    }
    if (*leftSignal == ']' and *rightSignal == ',') {
      return true;
    }
    if (*leftSignal == ',' and *rightSignal == ']') {
      return false;
    }
    // TODO: Check those 2
    if (*leftSignal == '[' and *rightSignal == ']') {
      return false;
    }
    if (*leftSignal == ']' and *rightSignal == '[') {
      return true;
    }
    if (isdigit(*rightSignal) and *leftSignal == ']')
      return true;
    if (isdigit(*leftSignal) and *rightSignal == ']')
      return false;
    // TODO: We expand the integer to a list once, then compare
    if (isdigit(*leftSignal) and *rightSignal == '[') {
      int rightBrackets{};
      while (*rightSignal == '[') {
        rightBrackets++;
        rightSignal++;
      }
      auto res =
          rightBiggerThanLeft(leftSignal, rightSignal, leftEnd, rightEnd, num);
      if (res != 2)
        return res;
      for (int i{}; i < rightBrackets; ++i) {
        if (*rightSignal == ',')
          return true;
        rightSignal++;
      }
    }
    if (isdigit(*rightSignal) and *leftSignal == '[') {
      int leftBrackets{};
      while (*leftSignal == '[') {
        leftBrackets++;
        leftSignal++;
      }
      auto res =
          rightBiggerThanLeft(leftSignal, rightSignal, leftEnd, rightEnd, num);
      if (res != 2)
        return res;
      for (int i{}; i < leftBrackets; ++i) {
        if (*leftSignal == ',')
          return false;
        leftSignal++;
      }
    }
    if (isdigit(*leftSignal) and isdigit(*rightSignal)) {
      auto leftNum = numFromIterator(leftSignal);
      auto rightNum = numFromIterator(rightSignal);
      if (leftNum < rightNum)
        return true;
      else if (leftNum > rightNum)
        return false;
    }
  }
  return 2;
}

int main() {
  auto input = readInput("/home/stephan/Dev/AoC/13/example");

  vector<Signals> signals;
  for (auto it = input.begin(); it < input.end();) {
    signals.push_back({*it, *(it + 1)});
    it += 3;
  }

  int Result{};
  for (int i = 0; i < signals.size(); ++i) {

    auto leftBegin = signals.at(i).left.begin();
    auto rightBegin = signals.at(i).right.begin();
    auto leftEnd = signals.at(i).left.end();
    auto rightEnd = signals.at(i).right.end();
    if (rightBiggerThanLeft(leftBegin, rightBegin, leftEnd, rightEnd, i + 1) ==
        1) {
      cout << i + 1 << endl;
      Result += i + 1;
    }
  }

  cout << Result << endl;
  return 0;
}
