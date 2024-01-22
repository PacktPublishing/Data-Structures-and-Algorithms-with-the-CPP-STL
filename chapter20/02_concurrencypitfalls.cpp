#include <atomic>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

// A simple function that we will run in a separate thread.
void threadTask(int n) {
  std::this_thread::sleep_for(std::chrono::seconds(n));
  std::cout << "Thread " << std::this_thread::get_id()
            << " completed after " << n << " seconds.\n";
}

// A function that performs a task and returns a result.
int performComputation(int value) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return (value * value);
}

int main() {
  // Start a thread that runs threadTask with n=2
  std::thread t(threadTask, 2);

  // task management with std::async and std::future
  std::future<int> futureResult = std::async(
      std::launch::async, performComputation, 5);

  // Atomic operation with std::atomic
  std::atomic<int> atomicCounter(0);

  // Demonstrate atomicity in concurrent operations
  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back([&atomicCounter]() {
      for (int j = 0; j < 100; ++j) {
        atomicCounter += 1; // Atomic increment
      }
    });
  }

  // Joining the initial thread to ensure it has finished
  // before main exits
  if (t.joinable()) { t.join(); }

  // Retrieving the result from the future
  int computationResult = futureResult.get();
  std::cout << "The result of the computation is "
            << computationResult << ".\n";

  // Joining all threads to ensure complete execution
  for (auto &th : threads) {
    if (th.joinable()) { th.join(); }
  }

  std::cout << "The final value of the atomic counter is "
            << atomicCounter << ".\n";
  return 0;
}