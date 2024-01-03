#include <iostream>
#include <vector>

class Sample {
public:
  Sample() { std::cout << "Constructor called!\n"; }

  Sample(const Sample &) {
    std::cout << "Copy Constructor called!\n";
  }

  Sample(Sample &&) noexcept {
    std::cout << "Move Constructor called!\n";
  }

  ~Sample() { std::cout << "Destructor called!\n"; }
};

Sample createSample() { return Sample(); }

int main() {
  std::cout << "Creating object via function return:\n";
  Sample obj = createSample();
  return 0;
}
