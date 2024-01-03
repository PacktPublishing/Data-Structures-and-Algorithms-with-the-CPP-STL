#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> numbers;

  std::generate_n(std::back_inserter(numbers), 10,
                  [n = 0]() mutable { return ++n; });

  for (auto num : numbers) { std::cout << num << " "; }
  std::cout << "\n";

  return 0;
}