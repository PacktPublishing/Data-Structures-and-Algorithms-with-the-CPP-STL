#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {10, 20, 30, 40, 50};

  const auto secondElement = numbers[1];
  std::cout << "The second element is: " << secondElement
            << "\n";

  // Beware: The following line can cause undefined
  // behavior!
  const auto outOfBoundsElement = numbers[10];
  std::cout << "Accessing an out-of-bounds index: "
            << outOfBoundsElement << "\n";

  return 0;
}