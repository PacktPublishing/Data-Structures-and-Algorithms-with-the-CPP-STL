#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  const long int dataSize = 1000;
  std::vector<long int> numbers(dataSize);
  std::iota(numbers.begin(), numbers.end(), 1);

  // Use std::transform_reduce to square each element and
  // sum them up in parallel
  long int parallelSumOfSquares = std::transform_reduce(
      std::execution::par, numbers.begin(), numbers.end(),
      0, // Initial value for the accumulation
      std::plus<long int>(),
      [](long int x) { return x * x; });

  std::cout << "Parallel Sum of Squares: "
            << parallelSumOfSquares << "\n";
  return 0;
}
