#include <iostream>
#include <thread>

// Shared variable
int counter = 0;

// Function that increments the counter
void incrementCounter() {
  for (int i = 0; i < 100000; ++i) {
    ++counter; // Race condition occurs here
  }
}

int main() {
  // Creating two threads that run incrementCounter()
  std::thread thread1(incrementCounter);
  std::thread thread2(incrementCounter);

  // Wait for both threads to finish
  thread1.join();
  thread2.join();

  // Print the final value of counter
  std::cout << "Final value of counter is: " << counter
            << std::endl;

  return 0;
}
