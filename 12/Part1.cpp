#include "input.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

struct Path {
  Point point;
  int cost;
  bool operator>(const Path &rhs) const { return cost > rhs.cost; }
};

vector<Point> getNeighbors(const Grid &grid, Point p) {
  auto curElevation = grid.get(p);

  if (curElevation == 'S')
    curElevation = 'a';
  else if (curElevation == 'E')
    curElevation = 'z';

  vector<Point> neighbors{
      {p.x + 1, p.y}, {p.x - 1, p.y}, {p.x, p.y + 1}, {p.x, p.y - 1}};
  vector<Point> validNeighbors{};
  for (auto &n : neighbors) {
    if (n.x >= 0 && n.y >= 0 && n.x < grid.x_width && n.y < grid.y_width) {
      if (grid.get(n) <= curElevation + 1)
        validNeighbors.push_back(n);
    }
  }
  return validNeighbors;
}

int solve(Grid &grid, Point start, Point end) {
  vector<Point> visited{};
  priority_queue<Path, vector<Path>, greater<Path>> shortestPath;
  shortestPath.push({start, 0});
  while (true) {
    auto currentPath = shortestPath.top();
    if (currentPath.point == end)
      return currentPath.cost;
    shortestPath.pop();
    if (find(visited.begin(), visited.end(), currentPath.point) !=
        visited.end())
      continue;
    visited.push_back(currentPath.point);
    auto neighbors = getNeighbors(grid, currentPath.point);
    for (auto &neighbor : neighbors) {
      if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
        shortestPath.push({neighbor, currentPath.cost + 1});
      }
    }
  }
  return 0;
}

int main() {
  // Read the data
  auto grid = readLineByLine("/home/stephan/Dev/AoC/12/input");
  cout << "x " << grid.x_width << endl;
  cout << "y " << grid.y_width << endl;

  Point start{0, 20};
  cout << grid.get(start) << endl;
  Point end{145, 20};
  cout << grid.get(end) << endl;
  for (auto &point : getNeighbors(grid, start))
    cout << "x " << point.x << ", y " << point.y << ", value "
         << grid.get(point) << endl;
  for (auto &point : getNeighbors(grid, end))
    cout << "x " << point.x << ", y " << point.y << ", value "
         << grid.get(point) << endl;
  cout << "Result " << solve(grid, start, end) << endl;
  return 0;
}
