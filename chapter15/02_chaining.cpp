#include <iostream>
#include <ranges>
#include <vector>

bool is_prime(int number) {
  if (number <= 1) return false;

  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) return false;
  }

  return true;
}

int main() {
  std::vector<int> nums = {4,  6,  8,  9,  10, 11,
                           13, 15, 17, 19, 23, 25};

  auto prime_greater_than_10 =
      nums |
      std::views::filter([](int n) { return n > 10; }) |
      std::views::filter(is_prime) | std::views::take(3);

  std::cout
      << "First three prime numbers greater than 10: ";

  for (int num : prime_greater_than_10) {
    std::cout << num << " ";
  }

  std::cout << "\n";
  return 0;
}