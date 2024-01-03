#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {10, 20, 30, 40, 50};

  try {
    const auto secondElement = numbers.at(1);
    std::cout << "The second element is: " << secondElement
              << "\n";
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  try {
    const auto outOfBoundsElement = numbers.at(10);
    std::cout << "Accessing an out-of-bounds index: "
              << outOfBoundsElement << "\n";
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}