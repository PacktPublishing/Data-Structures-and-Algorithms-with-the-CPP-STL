#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> scores = {85, 93, 78, 90, 96, 82};

  const auto max_it =
      std::max_element(scores.begin(), scores.end());

  if (max_it != scores.end()) {
    std::cout << "The highest score is: " << *max_it
              << "\n";
  }

  const auto min_it =
      std::min_element(scores.begin(), scores.end());

  if (min_it != scores.end()) {
    std::cout << "The lowest score is: " << *min_it
              << "\n";
  }

  const auto minmax =
      std::minmax_element(scores.begin(), scores.end());

  if (minmax.first != scores.end() &&
      minmax.second != scores.end()) {
    std::cout << "The lowest and highest scores are: "
              << *minmax.first << " and " << *minmax.second
              << ", respectively.\n";
  }

  std::vector<double> productPrices = {99.99, 79.99, 49.99,
                                       59.99, 89.99};

  // Find the minimum and maximum prices
  auto minmaxPrices = std::minmax_element(
      productPrices.begin(), productPrices.end());

  if (minmaxPrices.first != productPrices.end() &&
      minmaxPrices.second != productPrices.end()) {
    std::cout
        << "The cheapest and priciest products cost: $"
        << *minmaxPrices.first << " and $"
        << *minmaxPrices.second << ", respectively.\n";
  }

  return 0;
}