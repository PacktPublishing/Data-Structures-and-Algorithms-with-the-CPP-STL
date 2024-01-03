#include <iostream>
#include <vector>

int main() {
  std::vector<int> myVec;

  std::cout << "Initial size: " << myVec.size()
            << ", capacity: " << myVec.capacity() << "\n";

  for (auto i = 0; i < 10; ++i) {
    myVec.push_back(i);

    std::cout << "After adding " << i + 1
              << " integers, size: " << myVec.size()
              << ", capacity: " << myVec.capacity()
              << "\n";
  }

  myVec.resize(5);
  std::cout << "After resizing to 5 elements, size: "
            << myVec.size()
            << ", capacity: " << myVec.capacity() << "\n";

  myVec.shrink_to_fit();
  std::cout << "After shrinking to fit, size: "
            << myVec.size()
            << ", capacity: " << myVec.capacity() << "\n";

  myVec.push_back(5);
  std::cout << "After adding one more integer, size: "
            << myVec.size()
            << ", capacity: " << myVec.capacity() << "\n";

  return 0;
}