#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> values = {10, -1, 20, -2, 30};

  // Using std::replace to update a specific value
  std::replace(values.begin(), values.end(), -1,
               0); // Replace -1 with 0

  // Using std::replace_if to update based on a condition
  std::replace_if(
      values.begin(), values.end(),
      [](int value) {
        return value < 0;
      },  // Lambda function for condition
      0); // Replace negative values with 0

  // Printing the updated collection
  for (int value : values) { std::cout << value << " "; }
  std::cout << std::endl;

  return 0;
}
