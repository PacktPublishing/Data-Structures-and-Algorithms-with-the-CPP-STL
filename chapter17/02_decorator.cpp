#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// Decorator for adding logging to the compare function
template <typename Compare> class LoggingCompareDecorator {
public:
  LoggingCompareDecorator(Compare comp) : comp(comp) {}

  template <typename T>
  bool operator()(const T &lhs, const T &rhs) {
    bool result = comp(lhs, rhs);
    std::cout << "Comparing " << lhs << " and " << rhs
              << ": "
              << (result ? "lhs < rhs" : "lhs >= rhs")
              << "\n";
    return result;
  }

private:
  Compare comp;
};

int main() {
  std::vector<int> numbers = {4, 2, 5, 1, 3};

  // Original comparison function
  auto comp = std::less<int>();

  // Decorating the comparison function with logging
  LoggingCompareDecorator<decltype(comp)> decoratedComp(
      comp);

  // Using the decorated comparison in sort algorithm
  std::sort(numbers.begin(), numbers.end(), decoratedComp);

  // Output the sorted numbers
  std::cout << "Sorted numbers: ";
  for (int num : numbers) { std::cout << num << " "; }
  std::cout << "\n";

  return 0;
}
