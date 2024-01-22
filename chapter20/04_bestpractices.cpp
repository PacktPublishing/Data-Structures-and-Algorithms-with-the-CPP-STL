#include <algorithm>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

// A hypothetical concurrency-optimized container that uses
// fine-grained locking
template <typename T> class ConcurrentVector {
private:
  std::vector<T> data;
  mutable std::shared_mutex mutex;

public:
  // Inserts an element into the container with minimal
  // lock duration
  void insert(const T &value) {
    std::unique_lock<std::shared_mutex> lock(mutex);
    data.push_back(value);
  }

  // Finds an element with read access, demonstrating
  // shared locking
  bool find(const T &value) const {
    std::shared_lock<std::shared_mutex> lock(mutex);
    return std::find(data.begin(), data.end(), value) !=
           data.end();
  }

  // Size accessor that uses shared locking
  size_t size() const {
    std::shared_lock<std::shared_mutex> lock(mutex);
    return data.size();
  }
};

void performConcurrentOperations(
    ConcurrentVector<int> &concurrentContainer) {
  // Multiple threads perform operations on the container
  std::thread writer([&concurrentContainer]() {
    for (int i = 0; i < 100; ++i) {
      concurrentContainer.insert(i);
    }
  });

  std::thread reader([&concurrentContainer]() {
    for (int i = 0; i < 100; ++i) {
      if (concurrentContainer.find(i)) {
        std::cerr << "Value " << i
                  << " found in the container.\n";
      }
    }
  });

  // Join threads to ensure complete execution
  writer.join();
  reader.join();

  // Output the final size of the container
  std::cerr << "Final size of the container: "
            << concurrentContainer.size() << "\n";
}

int main() {
  ConcurrentVector<int> concurrentContainer;
  performConcurrentOperations(concurrentContainer);
  return 0;
}
