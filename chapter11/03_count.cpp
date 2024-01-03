#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> grades = {85, 90, 78, 92,
                             88, 76, 95, 89};

  const auto exact_count =
      std::count(grades.begin(), grades.end(), 90);

  std::cout << "Number of students who scored exactly 90: "
            << exact_count << "\n";

  const auto above_count =
      std::count_if(grades.begin(), grades.end(),
                    [](int grade) { return grade > 90; });

  std::cout << "Number of students who scored above 90: "
            << above_count << "\n";

  return 0;
}