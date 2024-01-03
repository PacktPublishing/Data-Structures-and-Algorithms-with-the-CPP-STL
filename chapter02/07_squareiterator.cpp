#include <iostream>
#include <iterator>
#include <vector>

class SquareIterator {
public:
  using iterator_category =
      std::random_access_iterator_tag;
  using value_type = int;
  using difference_type = std::ptrdiff_t;
  using pointer = int *;
  using reference = int &;

  explicit SquareIterator(pointer ptr) : ptr(ptr) {}

  value_type operator*() const { return (*ptr) * (*ptr); }
  pointer operator->() { return ptr; }

  SquareIterator &operator++() {
    ++ptr;
    return *this;
  }

  SquareIterator operator++(int) {
    SquareIterator tmp = *this;
    ++ptr;
    return tmp;
  }

  SquareIterator &operator+=(difference_type diff) {
    ptr += diff;
    return *this;
  }
  SquareIterator operator+(difference_type diff) const {
    return SquareIterator(ptr + diff);
  }

  value_type operator[](difference_type diff) const {
    return *(ptr + diff) * *(ptr + diff);
  }

  bool operator!=(const SquareIterator &other) const {
    return ptr != other.ptr;
  }

private:
  pointer ptr;
};

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  SquareIterator begin(vec.data());
  SquareIterator end(vec.data() + vec.size());

  for (auto it = begin; it != end; ++it) {
    std::cout << *it << ' ';
  }

  SquareIterator it = begin + 2;
  std::cout << "\nValue at position 2: " << *it;
  std::cout
      << "\nValue at position 3 using subscript operator: "
      << it[1];

  return 0;
}