#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  std::set<int> numbers = {5, 3, 8, 1, 4};

  auto [position, wasInserted] = numbers.insert(6);
  if (wasInserted) {
    std::cout << "6 was inserted into the set.\n";
  }

  auto result = numbers.insert(5);
  if (!result.second) {
    std::cout << "5 is already in the set.\n";
  }

  if (numbers.find(3) != numbers.end()) {
    std::cout << "3 is in the set.\n";
  }

  numbers.erase(1);

  std::cout << "Elements in the set:";
  for (int num : numbers) { std::cout << ' ' << num; }
  std::cout << '\n';

  std::set<int> moreNumbers = {9, 7, 2};
  numbers.merge(moreNumbers);

  std::cout << "After merging:";
  for (int num : numbers) { std::cout << ' ' << num; }
  std::cout << '\n';

  if (numbers.count(2)) {
    std::cout << "2 exists in the set.\n";
  }

  std::set<std::string, bool (*)(const std::string &,
                                 const std::string &)>
      caseInsensitiveSet{[](const std::string &lhs,
                            const std::string &rhs) {
        return std::lexicographical_compare(
            lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
            [](char a, char b) {
              return std::tolower(a) < std::tolower(b);
            });
      }};

  caseInsensitiveSet.insert("Hello");
  if (!caseInsensitiveSet.insert("hello").second) {
    std::cout << "Duplicate insertion (case-insensitive) "
                 "detected.\n";
  }

  return 0;
}