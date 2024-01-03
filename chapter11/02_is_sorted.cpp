#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> prices = {5.99, 10.49, 20.89, 25.55,
                                30.10};

  if (std::is_sorted(prices.begin(), prices.end())) {
    std::cout << "The product prices are sorted in "
                 "ascending order.\n";
  } else {
    std::cout << "The product prices are not sorted.\n";
  }

  auto partitionPoint = std::partition(
      prices.begin(), prices.end(),
      [](double price) { return price < 20.0; });

  if (std::is_partitioned(
          prices.begin(), prices.end(),
          [](double price) { return price < 20.0; })) {
    std::cout << "Prices are partitioned with prices less "
                 "than $20 first.\n";
  } else {
    std::cout << "Prices are not partitioned based on the "
                 "given criteria.\n";
  }

  std::vector<double> shuffledPrices = {25.55, 5.99, 30.10,
                                        10.49, 20.89};

  // Using std::is_permutation to ascertain if
  // shuffledPrices is a reordering of prices
  if (std::is_permutation(prices.begin(), prices.end(),
                          shuffledPrices.begin())) {
    std::cout
        << "Sequences are permutations of each other.\n";
  } else {
    std::cout << "Sequences are not permutations of each "
                 "other.\n";
  }

  return 0;
}