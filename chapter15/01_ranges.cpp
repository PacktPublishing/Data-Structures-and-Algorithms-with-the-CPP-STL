#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> data = {5, 2, 9, 1, 5, 6, 8, 7, 3, 4};

  // Create a view of the data that filters even numbers
  // and then sorts them
  auto even_sorted =
      data | std::views::filter([](int x) {
        return x % 2 == 0;
      }) |
      std::views::transform([](int x) { return -x; }) |
      std::ranges::to<std::vector<int>>();

  std::sort(even_sorted.begin(), even_sorted.end());

  // Display the sorted even numbers
  std::cout << "Sorted even numbers: ";

  for (int num : even_sorted) { std::cout << num << " "; }

  std::cout << "\n";
  return 0;
}