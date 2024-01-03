#include <iostream>

int main() {
  int *cArray = new int[5];

  for (int i = 0; i < 5; ++i) { cArray[i] = i + 1; }

  for (int i = 0; i < 5; ++i) {
    std::cout << cArray[i] << " ";
  }
  std::cout << "\n";

  const int newSize = 7;
  int *newCArray = new int[newSize];

  for (int i = 0; i < 5; ++i) { newCArray[i] = cArray[i]; }

  delete[] cArray;

  cArray = newCArray;

  for (int i = 0; i < newSize; ++i) {
    std::cout << cArray[i] << " ";
  }
  std::cout << "\n";

  int arraySize = newSize;
  std::cout << "Size of cArray: " << arraySize << "\n";

  delete[] cArray;

  return 0;
}