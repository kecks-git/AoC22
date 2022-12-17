#include "input.h"

#include <algorithm>
#include <fstream>
#include <ranges>

using namespace std;

std::vector<int> readLineByLineAndCallUpdate(const string &input,
                                             Base &object) {
  string line;
  ifstream myfile;

  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }

  std::vector<int> Result{};
  while (getline(myfile, line)) {
    object.update(line);
  }
  return Result;
}

std::vector<string> readInput(const std::string &input) {
  string line;
  ifstream myfile;

  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }

  std::vector<string> Result;
  while (getline(myfile, line)) {
    Result.push_back(line);
  }

  return Result;
}

Grid<char> readLineByLine(const string &input) {
  string line;
  ifstream myfile;

  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }

  Grid<char> Result;
  while (getline(myfile, line)) {
    std::ranges::copy(line.begin(), line.end(),
                      std::back_inserter(Result.data));
  }
  Result.x_width = line.size();
  Result.y_width = Result.data.size() / Result.x_width;
  return Result;
}

// function to split string into substrings on the
// basis of delimiter and return the substrings
// after split
vector<string> splitStrings(string &str, char dl) {
  string word = "";
  // to count the number of split strings
  int num = 0;
  // adding delimiter character at the end
  // of 'str'
  str = str + dl;

  // length of 'str'
  int l = str.size();

  // traversing 'str' from left to right
  vector<string> substr_list;
  for (int i = 0; i < l; i++) {

    // if str[i] is not equal to the delimiter
    // character then accumulate it to 'word'
    if (str[i] != dl)
      word = word + str[i];
    else {

      // if 'word' is not an empty string,
      // then add this 'word' to the array
      // 'substr_list[]'
      if ((int)word.size() != 0)
        substr_list.push_back(word);

      // reset 'word'
      word = "";
    }
  }

  // return the splitted strings
  return substr_list;
}