#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> grades = {85, 90, 78, 92,
                             88, 76, 95, 89};

  if (std::all_of(grades.begin(), grades.end(),
                  [](int grade) { return grade > 0; })) {
    std::cout << "All students have positive grades.\n";
  } else {
    std::cout << "Not all grades are positive.\n";
  }

  if (std::none_of(grades.begin(), grades.end(),
                   [](int grade) { return grade < 80; })) {
    std::cout
        << "No student has scored below passing marks.\n";
  } else {
    std::cout << "There are students who scored below "
                 "passing marks.\n";
  }

  if (std::any_of(grades.begin(), grades.end(),
                  [](int grade) { return grade >= 95; })) {
    std::cout << "There's at least one student with an "
                 "'exceptional' grade.\n";
  } else {
    std::cout
        << "No student has an 'exceptional' grade.\n";
  }

  return 0;
}