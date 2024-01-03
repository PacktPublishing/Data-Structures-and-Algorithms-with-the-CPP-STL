#include <iostream>
#include <vector>

int main() {
  std::vector<int> myVector(5);

  for (int i = 0; i < 5; ++i) { myVector[i] = i + 1; }

  for (int i = 5; i < 10; ++i) {
    myVector.push_back(i + 1);
  }

  for (int val : myVector) { std::cout << val << " "; }
  std::cout << "\n";

  return 0;
}
