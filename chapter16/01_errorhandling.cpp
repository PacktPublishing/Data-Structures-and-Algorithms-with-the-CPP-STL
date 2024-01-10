#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class CustomType {
public:
  CustomType(int value = 0) : value_(value) {}

  // Comparison operation
  bool operator<(const CustomType &other) const {
    return value_ < other.value_;
  }

  // Arithmetic operation
  CustomType operator+(const CustomType &other) const {
    return CustomType(value_ + other.value_);
  }

  // Copy operation
  CustomType(const CustomType &other)
      : value_(other.value_) {}

private:
  int value_{0};
};

class CustomContainer {
public:
  using iterator = std::vector<CustomType>::iterator;
  using const_iterator =
      std::vector<CustomType>::const_iterator;

  iterator begin() { return data_.begin(); }
  const_iterator begin() const { return data_.begin(); }
  iterator end() { return data_.end(); }
  const_iterator end() const { return data_.end(); }

  void push_back(const CustomType &value) {
    data_.push_back(value);
  }

private:
  std::vector<CustomType> data_;
};

int main() {
  CustomContainer container;
  container.push_back(CustomType(3));
  container.push_back(CustomType(1));
  container.push_back(CustomType(2));

  try {
    std::sort(container.begin(), container.end());
  } catch (const std::exception &e) {
    // Handle potential issues and provide meaningful
    // feedback
    std::cerr << "An error occurred: " << e.what() << "\n";
    return 1;
  }

  return 0;
}