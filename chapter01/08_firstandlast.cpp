#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {10, 20, 30, 40, 50};

  const auto firstElement = numbers.front();
  std::cout << "The first element is: " << firstElement
            << "\n";

  const auto lastElement = numbers.back();
  std::cout << "The last element is: " << lastElement
            << "\n";

  return 0;
}