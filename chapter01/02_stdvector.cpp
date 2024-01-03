#include <iostream>
#include <vector>

int main() {
  std::vector<int> stlVector = {1, 2, 3, 4, 5};

  for (const int val : stlVector) {
    std::cout << val << " ";
  }
  std::cout << "\n";

  stlVector.resize(7);

  for (const int val : stlVector) {
    std::cout << val << " ";
  }
  std::cout << "\n";

  std::cout << "Size of stlVector: " << stlVector.size()
            << "\n";

  return 0;
}