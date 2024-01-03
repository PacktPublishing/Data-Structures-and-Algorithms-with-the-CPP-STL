#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>

struct SensorData {
  int temperature{0};
  std::chrono::system_clock::time_point timestamp;
};

int main() {
  const auto now = std::chrono::system_clock::now();
  std::list<SensorData> sensorReadings = {
      {72, now - std::chrono::hours(10)},
      {73, now - std::chrono::hours(9)},
      {75, now - std::chrono::hours(8)},
      {75, now - std::chrono::hours(7)},
      {76, now - std::chrono::hours(6)},
      {78, now - std::chrono::hours(5)},
      {78, now - std::chrono::hours(4)},
      {79, now - std::chrono::hours(3)},
      {80, now - std::chrono::hours(2)},
      {81, now - std::chrono::hours(1)}};

  auto it = sensorReadings.begin();

  while (it != sensorReadings.end()) {
    it = std::adjacent_find(
        it, sensorReadings.end(),
        [](const SensorData &a, const SensorData &b) {
          return a.temperature == b.temperature;
        });

    if (it != sensorReadings.end()) {
      int duplicateValue = it->temperature;

      std::cout << "Found consecutive duplicate readings "
                   "of value: "
                << duplicateValue
                << " taken at the following times:\n";

      while (it != sensorReadings.end() &&
             it->temperature == duplicateValue) {
        const auto time =
            std::chrono::system_clock::to_time_t(
                it->timestamp);

        std::cout << "\t"
                  << std::put_time(std::localtime(&time),
                                   "%Y-%m-%d %H:%M:%S\n");
        ++it;
      }
    }
  }

  return 0;
}