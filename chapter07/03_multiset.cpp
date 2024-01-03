#include <iostream>
#include <iterator>
#include <set>
#include <string>

int main() {
  std::multiset<int> numbers = {5, 3, 8, 5, 3, 9, 4};

  numbers.insert(6);
  numbers.insert(5); // Inserting another duplicate

  for (int num : numbers) { std::cout << num << ' '; }
  std::cout << '\n';

  std::cout << "Number of 5s: " << numbers.count(5)
            << '\n';

  auto [begin, end] = numbers.equal_range(5);

  for (auto it = begin; it != end; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  numbers.erase(5);

  std::multiset<std::string, std::greater<>> words = {
      "apple", "banana", "cherry", "apple"};

  for (const auto &word : words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';

  std::multiset<int> dataset = {1, 2, 3, 4, 5,
                                6, 7, 8, 9, 10};

  const auto start = dataset.lower_bound(4);
  const auto stop = dataset.upper_bound(7);

  std::copy(start, stop,
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  return 0;
}