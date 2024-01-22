#include <future>
#include <iostream>
#include <thread>
#include <vector>

// Function to demonstrate the use of Thread Local Storage
void incrementThreadCounter() {
  // Unique to each thread
  thread_local int thread_counter = 0;
  thread_counter++;
  std::cout << "Thread " << std::this_thread::get_id()
            << " counter: " << thread_counter << "\n";
}

int main() {
  // Initiating a new thread using std::thread
  std::thread my_thread([] {
    std::cout << "Hello, Concurrent World!"
              << "\n";
  });

  // Ensure the main thread waits for my_thread to complete
  if (my_thread.joinable()) { my_thread.join(); }

  // Asynchronous operations w/std::async and std::future
  auto future_result =
      std::async([] { return "Response from async!"; });

  // Retrieve the result with std::future::get when ready
  std::cout << future_result.get() << "\n";

  // Demonstrating the use of Thread Local Storage (TLS)
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back(incrementThreadCounter);
  }

  // Join all threads to the main thread
  for (auto &thread : threads) {
    if (thread.joinable()) { thread.join(); }
  }

  return 0;
}