#include <array>
#include <iostream>
#include <list>
#include <vector>

template <typename Container>
void displayElements(const Container &c) {
  for (auto it = std::begin(c); it != std::end(c); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::list<int> lst = {6, 7, 8, 9, 10};
  std::array<int, 5> arr = {11, 12, 13, 14, 15};

  std::cout << "Elements in vector: ";
  displayElements(vec);

  std::cout << "Elements in list: ";
  displayElements(lst);

  std::cout << "Elements in array: ";
  displayElements(arr);

  return 0;
}