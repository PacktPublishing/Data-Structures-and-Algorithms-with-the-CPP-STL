#include <algorithm>
#include <iostream>
#include <vector>

// Custom type that is STL-compatible
class CustomType {
public:
  using iterator = std::vector<int>::iterator;
  using const_iterator = std::vector<int>::const_iterator;

  // Constructors
  CustomType() = default;
  CustomType(const CustomType &other) : data(other.data) {}
  CustomType(CustomType &&other) noexcept
      : data(std::move(other.data)) {}

  // Assignment operators
  CustomType &operator=(const CustomType &other) {
    if (this != &other) { data = other.data; }
    return *this;
  }

  CustomType &operator=(CustomType &&other) noexcept {
    if (this != &other) { data = std::move(other.data); }
    return *this;
  }

  ~CustomType() = default;

  // Size and capacity queries
  size_t size() const { return data.size(); }
  bool empty() const { return data.empty(); }

  // Element access and manipulation
  int &operator[](size_t index) { return data[index]; }

  const int &operator[](size_t index) const {
    return data[index];
  }

  void push_back(int value) { data.push_back(value); }
  void pop_back() { data.pop_back(); }

  // Iterators
  iterator begin() { return data.begin(); }
  const_iterator begin() const { return data.begin(); }
  iterator end() { return data.end(); }
  const_iterator end() const { return data.end(); }

private:
  std::vector<int> data;
};

int main() {
  CustomType custom;

  // Fill with some data
  for (int i = 0; i < 10; ++i) { custom.push_back(i); }

  // Use STL algorithm with our custom type
  std::for_each(
      custom.begin(), custom.end(),
      [](int &value) { std::cout << value << ' '; });

  return 0;
}