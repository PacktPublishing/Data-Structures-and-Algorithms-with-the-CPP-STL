#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  std::cout << "Original numbers: ";
  for (const auto num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  numbers.clear();

  std::cout << "After using clear(): ";

  // This loop will produce no output.
  for (const auto num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  std::cout << "Size of vector after clear(): "
            << numbers.size() << "\n";

  return 0;
}