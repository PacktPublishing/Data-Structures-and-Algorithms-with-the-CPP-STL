#include <algorithm>
#include <array>
#include <iostream>

constexpr std::array<int, 6> data = {1, 2, 3, 4, 3, 5};

constexpr bool contains(int value) {
  return std::find(data.begin(), data.end(), value) !=
         data.end();
}

constexpr size_t countOccurrences(int value) {
  return std::count(data.begin(), data.end(), value);
}

int main() {
  static_assert(contains(3));
  static_assert(countOccurrences(3) == 2);

  std::cout << "Array contains 3: " << contains(3) << "\n";
  std::cout << "Occurrences of 3: " << countOccurrences(3)
            << "\n";

  return 0;
}