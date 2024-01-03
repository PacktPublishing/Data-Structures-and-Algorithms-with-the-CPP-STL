#include <algorithm>
#include <iostream>
#include <vector>

// Define a generic comparison policy for numeric types
template <typename T> struct NumericComparison {
  bool operator()(const T &a, const T &b) const {
    return (a < b);
  }
};

// Define a specific comparison policy for strings
struct StringComparison {
  bool operator()(const std::string &a,
                  const std::string &b) const {
    return (a.length() < b.length());
  }
};

// Generic sort function using a policy
template <typename Iterator, typename ComparePolicy>
void sortWithPolicy(Iterator begin, Iterator end,
                    ComparePolicy comp) {
  std::sort(begin, end, comp);
}

int main() {
  // Example with numeric data
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9,
                              2, 6, 5, 3, 5};
  sortWithPolicy(numbers.begin(), numbers.end(),
                 NumericComparison<int>());

  for (int n : numbers) { std::cout << n << " "; }
  std::cout << "\n";

  // Example with string data
  std::vector<std::string> strings = {
      "apple", "pear", "banana", "cherry", "grape"};
  sortWithPolicy(strings.begin(), strings.end(),
                 StringComparison());

  for (const auto &str : strings) {
    std::cout << str << " ";
  }
  std::cout << "\n";

  return 0;
}
