#include <iostream>
#include <unordered_set>
#include <vector>

void displaySet(const std::unordered_set<int> &set) {
  for (const int &num : set) { std::cout << num << " "; }
  std::cout << '\n';
}

int main() {
  std::unordered_set<int> numbers;

  for (int i = 0; i < 10; ++i) { numbers.insert(i); }

  displaySet(numbers);

  int searchValue = 5;
  if (numbers.find(searchValue) != numbers.end()) {
    std::cout << searchValue << " found in the set."
              << '\n';
  } else {
    std::cout << searchValue << " not found in the set."
              << '\n';
  }

  numbers.erase(5);
  displaySet(numbers);

  std::cout << "Size: " << numbers.size() << '\n';
  std::cout << "Load factor: " << numbers.load_factor()
            << '\n';

  numbers.rehash(50);
  std::cout << "Number of buckets after rehash: "
            << numbers.bucket_count() << '\n';

  std::vector<int> moreNumbers = {100, 101, 102, 103};
  numbers.insert(moreNumbers.begin(), moreNumbers.end());
  displaySet(numbers);

  return 0;
}