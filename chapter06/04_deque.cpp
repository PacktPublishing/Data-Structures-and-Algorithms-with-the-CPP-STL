#include <algorithm>
#include <deque>
#include <iostream>

// A function to demonstrate using a deque as a sliding
// window over data.
void processInSlidingWindow(const std::deque<int> &data,
                            size_t windowSize) {
  for (size_t i = 0; i <= data.size() - windowSize; ++i) {
    int sum = 0;

    for (size_t j = i; j < i + windowSize; ++j) {
      sum += data[j];
    }

    std::cout << "Average of window starting at index "
              << i << ": "
              << static_cast<double>(sum) / windowSize
              << "\n";
  }
}

int main() {
  std::deque<int> numbers;

  for (int i = 1; i <= 5; ++i) {
    numbers.push_back(i * 10);   // 10, 20, ..., 50
    numbers.push_front(-i * 10); // -10, -20, ..., -50
  }

  std::cout << "Numbers in deque: ";
  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  numbers.pop_front();
  numbers.pop_back();

  std::cout << "After removing front and back: ";

  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  processInSlidingWindow(numbers, 3);

  std::transform(numbers.begin(), numbers.end(),
                 numbers.begin(),
                 [](int n) { return n * 2; });

  std::cout << "After doubling each element: ";

  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}