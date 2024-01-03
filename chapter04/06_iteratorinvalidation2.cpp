#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  numbers.reserve(1000);

  for (int i = 1; i <= 10; ++i) { numbers.push_back(i); }

  size_t positionOfFive =
      4; // 0-based index for number 5 in our vector
  std::cout << "Fifth element: " << numbers[positionOfFive]
            << "\n";

  numbers.insert(numbers.begin() + 5, 99);

  std::vector<int>::iterator it =
      numbers.begin() + positionOfFive;
  std::cout << "Element at the earlier fifth position "
               "after insertion: "
            << *it << "\n";

  // After inserting, refresh the iterator
  it = numbers.begin() + 6;

  std::sort(numbers.begin(), numbers.end());

  // Caution with Custom Comparators and Predicates:
  auto isOdd = [](int num) { return num % 2 != 0; };
  auto countOdd =
      std::count_if(numbers.begin(), numbers.end(), isOdd);
  std::cout << "Number of odd values: " << countOdd
            << "\n";

  // Note: The lambda function 'isOdd' is just a read-only
  // operation and doesn't modify the vector, ensuring we
  // don't have to worry about invalidation.

  return 0;
}