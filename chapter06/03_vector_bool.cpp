#include <iostream>
#include <vector>

int main() {
  std::vector<bool> boolVec = {true, false, true, true,
                               false};

  boolVec[1] = true;
  std::cout << "Second element: " << boolVec[1] << '\n';

  auto ref = boolVec[1];
  ref = false;

  std::cout << "Second element after modifying copy: "
            << boolVec[1] << '\n';

  // Iterating over the vector
  for (bool val : boolVec) { std::cout << val << ' '; }
  std::cout << '\n';

  // Pushing values
  boolVec.push_back(false);

  // Resizing
  boolVec.resize(10, true);

  // Capacity and size
  std::cout << "Size: " << boolVec.size()
            << ", Capacity: " << boolVec.capacity()
            << '\n';

  // Clearing the vector
  boolVec.clear();

  return 0;
}