#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<double> values = {8.0, 16.0, 64.0, 256.0,
                                4096.0};

  // Create a vector to store the calculated ratios
  std::vector<double> ratios(values.size());

  // Write a lambda to use in adjacent_difference
  auto lambda = [](double x, double y) {
    if (x == 0.0) {
      // Handle division by zero for the first element
      return 0.0;
    } else {
      // Calculate the ratio between y and x
      return y / x;
    }
  };

  // Calculate the ratios between consecutive elements
  std::adjacent_difference(values.begin(), values.end(),
                           ratios.begin(), lambda);

  // The first element in the ratios vector is 0.0 because
  // there's no previous element

  // Print the calculated ratios for the remaining elements
  std::cout << "Ratios between consecutive elements:\n";

  for (size_t i = 1; i < ratios.size(); ++i) {
    std::cout << "Ratio " << i << ": " << ratios[i]
              << "\n";
  }

  return 0;
}
