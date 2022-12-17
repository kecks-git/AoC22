#include "input.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Job {
public:
  int from;
  int to;
  explicit Job(string &in) {
    auto jobs = splitStrings(in, '-');
    from = stoi(jobs.at(0));
    to = stoi(jobs.at(1));
  }
  bool includes(const Job &other) {
    /* PART 1 */
    /*
        if (this->from <= other.from && this->to >= other.to)
          return true;
        else
          return false;
          */
    /* PART 2*/
    if (this->from <= other.to && this->to >= other.from)
      return true;
    else
      return false;
  }
  bool includesAny(Job &other) {
    if (other.includes(*this) or includes(other))
      return true;
    else
      return false;
    // if (this.from > other.from &&
    //  this.to < other.to) return true;
    // else if (this.from<other.from &&this.to> other.to) return true;
    // else return false;
  }
};
using Pair = pair<Job, Job>;

class Cleanup : public Base {
public:
  void update(const string &line) override {
    auto jobs = splitStrings(const_cast<string &>(line), ',');

    auto job1 = Job(jobs.at(0));
    auto job2 = Job(jobs.at(1));
    if (job1.includesAny(job2))
      ++m_total;
  }
  int m_total{};
};
int main() {
  Cleanup cl{};
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/4/input", cl);

  cout << cl.m_total << endl;
  return 0;
}
