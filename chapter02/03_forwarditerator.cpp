#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> flist = {10, 20, 30, 40, 50};

  std::cout << "Original list: ";
  for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  for (auto it = flist.begin(); it != flist.end(); ++it) {
    (*it)++;
  }

  std::cout << "Modified list: ";
  for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  return 0;
}