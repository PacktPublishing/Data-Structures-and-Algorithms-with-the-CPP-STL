#include <algorithm>
#include <iostream>
#include <list>

struct Student {
  std::string name;
  int grade{0};

  Student(std::string n, int g) : name(n), grade(g) {}
};

int main() {
  std::list<Student> students = {
      {"Lisa", 85},   {"Corbin", 92}, {"Aaron", 87},
      {"Daniel", 92}, {"Mandy", 78},  {"Regan", 92},
  };

  auto first_92 = std::find_if(
      students.begin(), students.end(),
      [](const Student &s) { return s.grade == 92; });

  if (first_92 != students.end()) {
    std::cout << first_92->name
              << " was the first to score 92.\n";
  }

  std::list<Student> searchFor = {{"", 92}};
  auto last_92 = std::find_end(
      students.begin(), students.end(), searchFor.begin(),
      searchFor.end(),
      [](const Student &s, const Student &value) {
        return s.grade == value.grade;
      });

  if (last_92 != students.end()) {
    std::cout << last_92->name
              << " was the last to score 92.\n";
  }

  return 0;
}