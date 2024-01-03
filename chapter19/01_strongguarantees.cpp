#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T> class CustomArray {
public:
  explicit CustomArray(size_t size)
      : size(size), data(std::make_unique<T[]>(size)) {
    // Initialize with default values, assuming T can be 
    // default constructed safely std::fill provides strong
    // guarantee
    std::fill(data.get(), data.get() + size, T());
  }

  // Copy constructor
  CustomArray(const CustomArray &other)
      : size(other.size),
        data(std::make_unique<T[]>(other.size)) {
    safeCopy(data.get(), other.data.get(), size);
  }

  // Move constructor - noexcept for strong guarantee
  // during container reallocation
  CustomArray(CustomArray &&other) noexcept
      : size(other.size), data(std::move(other.data)) {
    other.size = 0;
  }

  // Destructor is provided by std::unique_ptr for RAII

  // Copy assignment operator
  CustomArray &operator=(const CustomArray &other) {
    if (this != &other) {
      std::unique_ptr<T[]> newData(
          std::make_unique<T[]>(other.size));
      safeCopy(newData.get(), other.data.get(),
               other.size);
      size = other.size;
      data = std::move(
          newData); // Commit point, only change state here
    }

    return *this;
  }

  // Move assignment operator - noexcept for strong
  // guarantee during container reallocation
  CustomArray &operator=(CustomArray &&other) noexcept {
    if (this != &other) {
      data = std::move(other.data);
      size = other.size;
      other.size = 0;
    }

    return *this;
  }

private:
  size_t size{0};

  // RAII for resource management
  std::unique_ptr<T[]> data;

  // Private utility function to copy data safely with
  // strong exception guarantee
  void safeCopy(T *destination, T *source, size_t size) {
    // std::copy provides strong guarantee
    std::copy(source, source + size, destination);
  }
};

int main() {
  try {
    // CustomArray managing an array of 5 integers
    CustomArray<int> arr(5);
    // ... Use the array
  } catch (const std::exception &e) {
    std::cerr << "An exception occurred: " << e.what()
              << '\n';
    // CustomArray destructor will clean up resources if an
    // exception occurs
  }

  return 0;
}
