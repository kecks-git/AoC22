#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// void readToVector(const string &input, const string &separator, ) {
int main() {
  string line;
  ifstream myfile;
  myfile.open("input");

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }
  double maxFood{0};
  double curFood{0};
  while (getline(myfile, line)) {
    if (line.empty()) {
      if (curFood > maxFood)
        maxFood = curFood;
      curFood = 0;
    } else
      curFood += stoi(line);
  }
  cout << maxFood << endl;
  return maxFood;
}