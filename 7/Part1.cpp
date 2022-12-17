#include "input.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

static constexpr int MaxCapacity = 70'000'000;
static constexpr int NeededCapacity = 30'000'000;
static constexpr int DeleteCapacity = 40'572'957 + NeededCapacity - MaxCapacity;

class File {
public:
  File(int size, string name) : size(size), name(name) {
    cout << "New file: " << name << " size: " << size << endl;
  };
  string name;
  int size;
};
class Folder {
public:
  static int totalCapacity;
  static int toDelete;
  Folder(const string &name, Folder *parent) : name(name), parent(parent) {
    if (parent)
      cout << "New folder: " << name << " in " << parent->name << endl;
    else
      cout << "New folder: " << name << endl;
  };
  string name{};
  vector<Folder> folders;
  vector<File> files;
  Folder *parent;
  int Capacity{};
  int calculateCapacity() {
    Capacity = 0;
    for (auto &f : folders)
      Capacity += f.calculateCapacity();
    for (auto &f : files)
      Capacity += f.size;
    if (Capacity <= 100'000)
      totalCapacity += Capacity;
    cout << "Folder " << name << ", Capacity: " << Capacity << endl;
    if (Capacity > DeleteCapacity) {
      if (Capacity < toDelete)
        toDelete = Capacity;
    }
    return Capacity;
  }
};

enum class Mode { ls, cd };

class Filesystem : public Base {
public:
  void update(const string &line) override {
    auto str = splitStrings(const_cast<string &>(line), ' ');
    if (str.at(0) == "$") {
      if (str.at(1) == "ls")
        mode = Mode::ls;
      else {
        mode = Mode::cd;
        if (str.at(2) == "/") {
          return;
        } else if (str.at(2) == "..") {
          pwd = pwd->parent;
        } else {
          // back = pwd;
          for (auto &f : pwd->folders) {
            if (f.name == str.at(2))
              pwd = &f;
          }
        }
      }
    } else {
      if (mode == Mode::ls) {
        if (str.at(0) == "dir") {
          cout << "In " << pwd->name << endl;
          pwd->folders.push_back(Folder{str.at(1), pwd});
        } else {
          cout << "In " << pwd->name << endl;
          pwd->files.push_back(File{stoi(str.at(0)), str.at(1)});
        }
      }
    }
  }
  Folder root{"/", nullptr};
  Folder *pwd = &root;
  Mode mode;
};

int Folder::totalCapacity = 0;
int Folder::toDelete = 40'000'000;

int main() {
  Filesystem myFS{};
  // Read the data
  readLineByLineAndCallUpdate("/home/stephan/Dev/AoC/7/input", myFS);
  myFS.root.totalCapacity = 0;
  for (auto &folder : myFS.root.folders) {
    cout << folder.name << endl;
    for (auto &file : folder.files) {
      cout << file.name << " " << file.size << endl;
    }
  }

  myFS.root.calculateCapacity();
  cout << myFS.root.totalCapacity << endl;
  cout << DeleteCapacity << endl;
  cout << "To delete: " << myFS.root.toDelete << endl;
  return 0;
}
