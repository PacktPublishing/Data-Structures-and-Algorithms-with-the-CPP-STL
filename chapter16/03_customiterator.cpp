#include <iostream>
#include <iterator>
#include <vector>

// Define a custom data structure for custom iterators.
class MyContainer {
public:
  MyContainer(std::initializer_list<int> values)
      : data(values) {}

  // Custom iterator for MyContainer.
  class iterator {

  private:
    std::vector<int>::iterator it;

  public:
    iterator(std::vector<int>::iterator iter) : it(iter) {}

    // Dereferencing operator to access the underlying
    // data.
    int &operator*() { return *it; }

    // Increment operator to navigate through the data.
    iterator &operator++() {
      ++it;
      return *this;
    }

    // Comparison operator to determine the relative
    // positions of two iterators.
    bool operator==(const iterator &other) const {
      return it == other.it;
    }

    bool operator!=(const iterator &other) const {
      return it != other.it;
    }
  };

  // Begin and end functions to provide iterators.
  iterator begin() { return iterator(data.begin()); }
  iterator end() { return iterator(data.end()); }

  // Additional member functions for MyContainer as needed.
private:
  std::vector<int> data;
};

int main() {
  MyContainer container = {1, 2, 3, 4, 5};

  // Using custom iterators to iterate through the data.
  for (MyContainer::iterator it = container.begin();
       it != container.end(); ++it) {
    std::cout << *it << " ";
  }

  std::cout << "\n";
  return 0;
}
