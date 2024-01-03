#include <iostream>
#include <iterator>
#include <vector>

struct RGBA {
  uint8_t r, g, b, a;
};

class AlphaIterator {
public:
  using iterator_category = std::input_iterator_tag;
  using value_type = uint8_t;
  using difference_type = std::ptrdiff_t;
  using pointer = uint8_t *;
  using reference = uint8_t &;

  explicit AlphaIterator(std::vector<RGBA>::iterator itr)
      : itr_(itr) {}

  reference operator*() { return itr_->a; }

  AlphaIterator &operator++() {
    ++itr_;
    return *this;
  }

  AlphaIterator operator++(int) {
    AlphaIterator tmp(*this);
    ++itr_;
    return tmp;
  }

  bool operator==(const AlphaIterator &other) const {
    return itr_ == other.itr_;
  }

  bool operator!=(const AlphaIterator &other) const {
    return itr_ != other.itr_;
  }

private:
  std::vector<RGBA>::iterator itr_;
};

int main() {
  std::vector<RGBA> bitmap = {
      {255, 0, 0, 128}, {0, 255, 0, 200}, {0, 0, 255, 255},
      // ... add more colors
  };

  std::cout << "Alpha values:\n";

  for (AlphaIterator it = AlphaIterator(bitmap.begin());
       it != AlphaIterator(bitmap.end()); ++it) {
    std::cout << static_cast<int>(*it) << " ";
  }
  std::cout << "\n";

  return 0;
}