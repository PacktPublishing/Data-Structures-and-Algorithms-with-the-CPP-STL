#include <iostream>
#include <memory>
#include <vector>

template <typename T> class CustomAllocator {
public:
  using value_type = T;

  CustomAllocator() noexcept {}

  template <typename U>
  CustomAllocator(const CustomAllocator<U> &) noexcept {}

  T *allocate(std::size_t n) {
    std::cout << "Allocating " << n << " objects of size "
              << sizeof(T) << " bytes.\n";
    return static_cast<T *>(::operator new(n * sizeof(T)));
  }

  void deallocate(T *p, std::size_t) noexcept {
    std::cout << "Deallocating memory.\n";
    ::operator delete(p);
  }

  template <typename U, typename... Args>
  void construct(U *p, Args &&...args) {
    std::cout << "Constructing object.\n";
    new (p) U(std::forward<Args>(args)...);
  }

  template <typename U> void destroy(U *p) {
    std::cout << "Destroying object.\n";
    p->~U();
  }
};

int main() {
  std::vector<int, CustomAllocator<int>> numbers;

  std::cout << "Pushing back numbers 1 to 5:\n";
  for (int i = 1; i <= 5; ++i) { numbers.push_back(i); }

  std::cout << "\nClearing the vector:\n";
  numbers.clear();

  return 0;
}