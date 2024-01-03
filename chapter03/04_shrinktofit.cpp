#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  numbers.reserve(1000);
  std::cout << "Initial capacity: " << numbers.capacity()
            << "\n";

  for (auto i = 0; i < 10; ++i) { numbers.push_back(i); }

  std::cout << "Size after adding 10 elements: "
            << numbers.size() << "\n";
  std::cout << "Capacity after adding 10 elements: "
            << numbers.capacity() << "\n";

  numbers.shrink_to_fit();

  std::cout << "Size after shrink_to_fit: "
            << numbers.size() << "\n";
  std::cout << "Capacity after shrink_to_fit: "
            << numbers.capacity() << "\n";

  return 0;
}