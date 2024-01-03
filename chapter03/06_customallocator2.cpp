#include <iostream>
#include <memory>
#include <stack>
#include <vector>

template <typename T> class CustomAllocator {
public:
  using value_type = T;

  CustomAllocator() = default;

  T *allocate(std::size_t n) {
    if (freeStart + n * sizeof(T) > pool + poolSize) {
      throw std::bad_alloc();
    }

    T *result = reinterpret_cast<T *>(freeStart);
    allocatedBlocks.push(freeStart);
    freeStart += n * sizeof(T);

    return result;
  }

  void deallocate(T *p, std::size_t n) {
    if (allocatedBlocks.empty() ||
        reinterpret_cast<char *>(p) !=
            allocatedBlocks.top()) {
      throw std::runtime_error(
          "Deallocation out of order or for unallocated "
          "memory.");
    }
    allocatedBlocks.pop();
    freeStart -= n * sizeof(T);
  }

  template <typename U, typename... Args>
  void construct(U *p, Args &&...args) {
    new (p) U(std::forward<Args>(args)...);
  }

  template <typename U> void destroy(U *p) { p->~U(); }

  // Define the rebind template to make the allocator
  // rebindable
  template <typename U> struct rebind {
    typedef CustomAllocator<U> other;
  };

  // Constructor for rebinding
  template <typename U>
  CustomAllocator(const CustomAllocator<U> &) {
    // This constructor is used in the rebinding process
  }

private:
  static const size_t poolSize =
      1024; // Define a fixed-size memory pool

  char pool[poolSize];
  char *freeStart = pool;
  std::stack<char *> allocatedBlocks;
};

int main() {
  std::vector<int, CustomAllocator<int>>
      customAllocatedVector;

  for (int i = 0; i < 10;
       ++i) { // Use a smaller number for demo purposes
    customAllocatedVector.push_back(i);
  }

  for (int val : customAllocatedVector) {
    std::cout << val << ' ';
  }

  return 0;
}