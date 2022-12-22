#include "input.h"
#include <assert.h>
#include <cmath>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class MovingPoint {
public:
  Point point;

  Point move(const char *direction, const char *length) {
    if (*direction == 'U')
      point.y += atoi(length);
    else if (*direction == 'D')
      point.y -= atoi(length);
    else if (*direction == 'R')
      point.x += atoi(length);
    else if (*direction == 'L')
      point.x -= atoi(length);
    return point;
  }
  Point moveOne(const char *direction) {
    if (*direction == 'U')
      point.y += 1;
    else if (*direction == 'D')
      point.y -= 1;
    else if (*direction == 'R')
      point.x += 1;
    else if (*direction == 'L')
      point.x -= 1;
    return point;
  }
  void followX(const MovingPoint &other) {
    if (abs(point.x - other.point.x) >= 1) {
      if (point.x > other.point.x) {
        --point.x;
      } else if (point.x < other.point.x) {
        ++point.x;
      }
    }
  }
  void followY(const MovingPoint &other) {
    if (abs(point.y - other.point.y) >= 1) {
      if (point.y > other.point.y) {
        --point.y;
      } else if (point.y < other.point.y) {
        ++point.y;
      }
    }
  }
  Point follow(const MovingPoint &other) {
    followX(other);
    followY(other);
    return point;
  }

  void printPosition() {
    cout << "x: " << point.x << ", y: " << point.y << endl;
  }
};

class Head : public MovingPoint {};
class Tail : public MovingPoint {};

int doCalc(const std::string &filename) {
  // Read the data
  auto lines = readInput("/home/stephan/Dev/AoC/9/" + filename);
  /*
    // Part 1
    set<Point> result;
    Head head;
    Tail tail;

    for (auto &line : lines) {
      cout << line << endl;
      auto res = splitStrings(line, ' ');
      head.move(res.at(0).c_str(), res.at(1).c_str());
      cout << "Head " << endl;
      head.printPosition();
      result.insert(tail.point);
      while (not head.point.isNeighbor(tail.point)) {
        result.insert(tail.follow(head));
        cout << "Tail " << endl;
        tail.printPosition();
      }
    }
    cout << "Result " << result.size() << endl;
    */
  // Part 2
  static constexpr int length = 10;
  set<Point> result2;
  vector<MovingPoint> rope(length);

  cout << "Size " << rope.size() << endl;
  result2.insert(Point{});
  for (auto &line : lines) {
    auto res = splitStrings(line, ' ');
    int range = atoi(res.at(1).c_str());
    while (range != 0) {
      rope.at(0).moveOne(res.at(0).c_str());
      if (range > 0)
        range -= 1;
      else if (range < 0)
        range += 1;
      cout << range << endl;
      for (auto it = rope.begin() + 1; it != rope.end() - 1; ++it) {
        if (not it->point.isNeighbor((it - 1)->point)) {
          it->follow(const_cast<const MovingPoint &>(*(it - 1)));
        }
      }
      auto &ropeTail = rope.at(length - 1);
      if (not ropeTail.point.isNeighbor(rope.at(length - 2).point)) {
        ropeTail.printPosition();
        result2.insert(ropeTail.follow(rope.at(length - 2)));
      }
    }
  }

  return result2.size();
}
