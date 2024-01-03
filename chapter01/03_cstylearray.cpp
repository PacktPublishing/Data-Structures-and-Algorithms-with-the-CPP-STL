#include <iostream>

int main() {
  int *cArray = new int[5];

  for (int i = 0; i < 5; ++i) { cArray[i] = i + 1; }

  int *temp = new int[10];
  for (int i = 0; i < 5; ++i) { temp[i] = cArray[i]; }
  delete[] cArray; // Important: free the old memory
  cArray = temp;

  for (int i = 5; i < 10; ++i) { cArray[i] = i + 1; }

  for (int i = 0; i < 10; ++i) {
    std::cout << cArray[i] << " ";
  }
  std::cout << "\n";

  delete[] cArray;

  return 0;
}