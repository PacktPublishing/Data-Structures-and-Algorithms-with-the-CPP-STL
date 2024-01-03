#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9};

  // Let's mistakenly provide an end iterator beyond the
  // actual end of the vector.
  std::vector<int>::iterator invalid = numbers.end() + 1;

  // Uncommenting the following line can lead to undefined
  // behavior due to the invalid range.
  // std::sort(numbers.begin(), invalidEnd);

  // This comparator will return true even when both
  // elements are equal. This violates the strict weak
  // ordering.
  auto badComparator = [](int a, int b) { return a <= b; };

  // Using such a comparator can lead to unexpected
  // results.
  std::sort(numbers.begin(), numbers.end(), badComparator);

  // Displaying the sorted array (might be unexpectedly
  // sorted or cause other issues)
  for (int num : numbers) { std::cout << num << " "; }
  std::cout << "\n";

  return 0;
}