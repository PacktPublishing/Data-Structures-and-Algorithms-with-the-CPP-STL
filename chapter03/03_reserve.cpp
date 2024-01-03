#include <chrono>
#include <iostream>
#include <vector>

int main() {
  constexpr size_t numberOfElements = 100'000;

  std::vector<int> numbers1;
  auto start1 = std::chrono::high_resolution_clock::now();
  for (auto i = 0; i < numberOfElements; ++i) {
    numbers1.push_back(i);
  }
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed1 = end1 - start1;
  std::cout << "Time without reserve: " << elapsed1.count()
            << " seconds\n";

  std::vector<int> numbers2;
  numbers2.reserve(
      numberOfElements); // Reserve memory upfront.

  auto start2 = std::chrono::high_resolution_clock::now();
  for (auto i = 0; i < numberOfElements; ++i) {
    numbers2.push_back(i);
  }
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed2 = end2 - start2;
  std::cout << "Time with reserve: " << elapsed2.count()
            << " seconds\n";

  return 0;
}