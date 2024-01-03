#include <algorithm>
#include <iostream>
#include <list>

void display(const std::list<int> &lst) {
  for (const auto &val : lst) { std::cout << val << " "; }
  std::cout << "\n";
}

int main() {
  std::list<int> numbers = {5, 1, 8, 3, 7};

  std::cout << "Numbers in reverse: ";
  for (auto it = numbers.rbegin(); it != numbers.rend();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  auto pos = std::find(numbers.begin(), numbers.end(), 8);
  numbers.insert(pos, 2112);
  std::cout << "After insertion: ";
  display(numbers);

  numbers.sort();
  std::list<int> more_numbers = {2, 6, 4};
  more_numbers.sort();
  numbers.merge(more_numbers);
  std::cout << "After sorting and merging: ";
  display(numbers);

  std::list<int> additional_numbers = {99, 100, 101};
  numbers.splice(numbers.end(), additional_numbers);
  std::cout << "After splicing: ";
  display(numbers);

  numbers.remove_if([](int n) { return n % 2 == 0; });
  std::cout << "After removing all even numbers: ";
  display(numbers);

  return 0;
}