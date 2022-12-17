#include <assert.h>
#include <string>
#include <vector>

class Base {
public:
  virtual void update(const std::string &line) = 0;
};

std::vector<std::string> splitStrings(std::string &str, char dl);
std::vector<int> readLineByLineAndCallUpdate(const std::string &input,
                                             Base &object);
struct Point {
  int x;
  int y;
  auto operator<=>(const Point &) const = default;
};

std::vector<std::string> readInput(const std::string &input);

template <typename T> struct Grid {
  std::vector<T> data;
  int x_width{};
  int y_width{};
  T get(Point p) const {
    assert(p.x < x_width);
    assert(p.y < y_width);
    return data.at(p.x + p.y * x_width);
  };
  void set(Point p, T value) {
    assert(p.x < x_width);
    assert(p.y < y_width);
    data.at(p.x + p.y * x_width) = value;
  };
};

Grid<char> readLineByLine(const std::string &input);
