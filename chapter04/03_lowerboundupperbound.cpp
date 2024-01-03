#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 3, 3, 5, 7};

  int val1 = 3;
  auto low1 = std::lower_bound(numbers.begin(),
                               numbers.end(), val1);
  std::cout << "std::lower_bound for value " << val1
            << ": " << (low1 - numbers.begin()) << "\n";

  int val2 = 4;
  auto low2 = std::lower_bound(numbers.begin(),
                               numbers.end(), val2);
  std::cout << "std::lower_bound for value " << val2
            << ": " << (low2 - numbers.begin()) << "\n";

  int val3 = 3;
  auto up1 = std::upper_bound(numbers.begin(),
                              numbers.end(), val3);
  std::cout << "std::upper_bound for value " << val3
            << ": " << (up1 - numbers.begin()) << "\n";

  return 0;
}