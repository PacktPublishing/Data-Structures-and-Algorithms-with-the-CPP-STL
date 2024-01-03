#include <algorithm>
#include <iostream>
#include <set>
#include <string>

struct Student {
  std::string name;
  int grade{0};

  bool operator<(const Student &other) const {
    return grade < other.grade; // Sorting based on grade
  }
};

int main() {
  std::set<Student> students = {
      {"Amanda", 68},  {"Claire", 72}, {"Aaron", 85},
      {"William", 85}, {"April", 92},  {"Bryan", 96},
      {"Chelsea", 98}};

  Student searchStudent{"", 85};

  const auto lb = std::lower_bound(
      students.begin(), students.end(), searchStudent);

  if (lb != students.end() && lb->grade == 85) {
    std::cout
        << lb->name
        << " is the first student with a grade of 85.\n";
  }

  const auto ub = std::upper_bound(
      students.begin(), students.end(), searchStudent);

  if (ub != students.end()) {
    std::cout << ub->name
              << " is the next student after the last one "
                 "with a grade of 85, with a grade of "
              << ub->grade << ".\n";
  }

  if (std::binary_search(students.begin(), students.end(),
                         searchStudent)) {
    std::cout << "There's at least one student with a "
                 "grade of 85.\n";
  } else {
    std::cout << "No student has scored an 85.\n";
  }

  return 0;
}