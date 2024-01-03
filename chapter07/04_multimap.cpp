#include <iostream>
#include <map>
#include <string>

int main() {
  std::multimap<std::string, int> grades;

  grades.insert({"John", 85});
  grades.insert({"Corbin", 78});
  grades.insert({"Regan", 92});
  grades.insert({"John", 90}); // John has another grade

  for (const auto &[name, score] : grades) {
    std::cout << name << " scored " << score << '\n';
  }
  std::cout << '\n';

  std::cout << "John's grade count: "
            << grades.count("John") << '\n';

  auto [begin, end] = grades.equal_range("John");
  for (auto it = begin; it != end; ++it) {
    std::cout << it->first << " scored " << it->second
              << '\n';
  }
  std::cout << '\n';

  grades.erase("John");

  std::multimap<std::string, int, std::greater<>>
      reverseGrades = {{"Mandy", 82},
                       {"Mandy", 87},
                       {"Aaron", 90},
                       {"Dan", 76}};

  for (const auto &[name, score] : reverseGrades) {
    std::cout << name << " scored " << score << '\n';
  }

  return 0;
}