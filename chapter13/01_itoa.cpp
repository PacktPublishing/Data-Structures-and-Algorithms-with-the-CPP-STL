#include <iostream>
#include <numeric>
#include <vector>

int main() {

  const int numTimeSteps = 100;

  std::vector<double> timeSteps(numTimeSteps);

  // Generate a sequence of time steps using std::iota
  double timeStep = 0.01; // Time step size
  std::iota(timeSteps.begin(), timeSteps.end(), 0);

  // Scale the time steps to represent actual time
  for (double &t : timeSteps) { t *= timeStep; }

  // Now, timeSteps contains a sequence of time points for
  // simulation

  // Simulate a simple system over time (e.g., particle
  // movement)
  for (const double t : timeSteps) {
    // Simulate the system's behavior at time t
    // ...
    std::cout << "Time: " << t << std::endl;
  }

  return 0;
}
