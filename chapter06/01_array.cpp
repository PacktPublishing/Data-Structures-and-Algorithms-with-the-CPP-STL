#include <algorithm>
#include <array>
#include <iostream>

struct Point {
  int x{0}, y{0};
};

constexpr int sumArray(const std::array<int, 5> &arr) {
  int sum = 0;
  for (const auto &val : arr) { sum += val; }
  return sum;
}

int main() {
  std::array<int, 5> numbers = {5, 3, 8, 1, 4};
  std::array<Point, 3> points = {{{1, 2}, {3, 4}, {5, 6}}};

  // Demonstrating structured bindings with &[x, y]
  for (const auto &[x, y] : points) {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  constexpr std::array<int, 5> constNumbers = {1, 2, 3, 4,
                                               5};

  constexpr int totalSum = sumArray(constNumbers);

  std::cout << "\nCompile-time sum of array elements: "
            << totalSum << "\n";

  std::sort(numbers.begin(), numbers.end());

  std::cout << "\nSorted numbers: ";
  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  int searchFor = 3;

  if (std::find(numbers.begin(), numbers.end(),
                searchFor) != numbers.end()) {
    std::cout << "\nFound " << searchFor
              << " in the array.\n";
  } else {
    std::cout << "\nDidn't find " << searchFor
              << " in the array.\n";
  }

  return 0;
}