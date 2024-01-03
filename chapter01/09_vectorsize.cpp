#include <iostream>
#include <vector>

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};

  const auto elementCount = data.size();
  std::cout << "Vector contains " << elementCount
            << " elements.\n";

  return 0;
}