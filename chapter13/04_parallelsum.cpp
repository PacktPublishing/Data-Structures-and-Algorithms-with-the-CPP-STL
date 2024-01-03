#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  // Create a large vector of numbers
  const int dataSize = 1000000;
  std::vector<int> numbers(dataSize);

  // Initialize the vector with some values (e.g., 1 to
  // dataSize)
  std::iota(numbers.begin(), numbers.end(), 1);

  // Calculate the sum of the numbers in parallel
  int parallelSum = std::reduce(
      std::execution::par, numbers.begin(), numbers.end());

  std::cout << "Parallel Sum: " << parallelSum
            << std::endl;
  return 0;
}