#include <iostream>
#include <vector>

int main() {
  std::vector<int> scores;

  std::cout << "Initial size of scores: " << scores.size()
            << "\n";

  scores.push_back(95);

  std::cout << "Size after adding one score: "
            << scores.size() << "\n";
  std::cout << "Recently added score: " << scores[0]
            << "\n";

  return 0;
}