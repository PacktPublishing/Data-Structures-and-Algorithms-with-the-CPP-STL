#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  std::unordered_multiset<std::string> fruits;

  fruits.insert("apple");
  fruits.insert("banana");
  fruits.insert("apple");
  fruits.insert("orange");
  fruits.insert("apple");
  fruits.insert("mango");
  fruits.insert("banana");

  const auto appleCount = fruits.count("apple");
  std::cout << "Number of apples: " << appleCount << '\n';

  auto found = fruits.find("orange");
  if (found != fruits.end()) {
    std::cout << "Found: " << *found << '\n';
  } else {
    std::cout << "Orange not found!" << '\n';
  }

  auto range = fruits.equal_range("banana");
  for (auto itr = range.first; itr != range.second;
       ++itr) {
    std::cout << *itr << " ";
  }
  std::cout << '\n';

  fruits.erase("apple");
  std::cout << "Number of apples after erase: "
            << fruits.count("apple") << '\n';
  std::cout << "Load factor: " << fruits.load_factor()
            << '\n';
  std::cout << "Bucket count: " << fruits.bucket_count()
            << '\n';

  fruits.rehash(50);
  std::cout << "Bucket count after rehashing: "
            << fruits.bucket_count() << '\n';

  for (const auto &fruit : fruits) {
    std::cout << fruit << " ";
  }
  std::cout << '\n';

  return 0;
}