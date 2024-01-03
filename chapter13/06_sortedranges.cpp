#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> d = {10, 20, 30, 40, 50,
                        60, 70, 80, 90};
  int tgt = 40;
  auto lb = std::lower_bound(d.begin(), d.end(), tgt);
  auto ub = std::upper_bound(d.begin(), d.end(), tgt);

  bool exists =
      std::binary_search(d.begin(), d.end(), tgt);

  std::vector<int> set1 = {10, 20, 30, 40, 50};
  std::vector<int> set2 = {30, 40, 50, 60, 70};
  std::vector<int> intersection(
      std::min(set1.size(), set2.size()));

  auto it = std::set_intersection(set1.begin(), set1.end(),
                                  set2.begin(), set2.end(),
                                  intersection.begin());

  std::vector<int> difference(
      std::max(set1.size(), set2.size()));

  auto diffEnd = std::set_difference(
      set1.begin(), set1.end(), set2.begin(), set2.end(),
      difference.begin());
  bool isSorted = std::is_sorted(d.begin(), d.end());

  std::cout << "Lower Bound: "
            << std::distance(d.begin(), lb) << "\n";
  std::cout << "Upper Bound: "
            << std::distance(d.begin(), ub) << "\n";
  std::cout << "Exists: " << exists << "\n";

  std::cout << "Intersection: ";
  for (auto i = intersection.begin(); i != it; ++i)
    std::cout << *i << " ";
  std::cout << "\n";

  std::cout << "Difference: ";
  for (auto i = difference.begin(); i != diffEnd; ++i)
    std::cout << *i << " ";
  std::cout << "\n";

  std::cout << "Is Sorted: " << isSorted << "\n";
  return 0;
}
