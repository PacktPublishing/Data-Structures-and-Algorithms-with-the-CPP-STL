#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  std::vector<int>::iterator it = numbers.begin() + 2;
  std::cout << "The element at the iterator before "
               "push_back: "
            << *it << "\n";

  for (int i = 6; i <= 1000; i++) { numbers.push_back(i); }

  std::cout << "The element at the iterator after "
               "push_back: "
            << *it << "\n";

  it = numbers.begin() + 2;
  numbers.insert(it, 99);

  it = numbers.begin() + 3;
  numbers.erase(it);

  return 0;
}