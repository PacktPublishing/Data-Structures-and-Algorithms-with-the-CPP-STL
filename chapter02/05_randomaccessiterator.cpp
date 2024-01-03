#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex vecMutex;

void add_to_vector(std::vector<int> &numbers, int value) {
  std::lock_guard<std::mutex> guard(vecMutex);
  numbers.push_back(value);
}

void print_vector(const std::vector<int> &numbers) {
  std::lock_guard<std::mutex> guard(vecMutex);
  for (int num : numbers) { std::cout << num << " "; }
  std::cout << "\n";
}

int main() {
  std::vector<int> numbers;
  std::thread t1(add_to_vector, std::ref(numbers), 1);
  std::thread t2(add_to_vector, std::ref(numbers), 2);
  t1.join();
  t2.join();
  std::thread t3(print_vector, std::ref(numbers));
  t3.join();
  return 0;
}