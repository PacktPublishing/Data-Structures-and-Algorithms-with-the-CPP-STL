#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {10, 20, 30, 40, 50};

  for (auto it = numbers.begin(); it != numbers.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  return 0;
}