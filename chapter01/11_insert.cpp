#include <iostream>
#include <vector>

int main() {
  std::vector<int> scores = {90, 92, 97};

  std::cout << "Initial scores:";
  for (int score : scores) { std::cout << " " << score; }
  std::cout << "\n";

  scores.push_back(95);

  std::cout << "Scores after adding 95 to the end:";
  for (int score : scores) { std::cout << " " << score; }
  std::cout << "\n";

  scores.insert(scores.begin() + 2, 85);

  std::cout << "Scores after inserting 85 at the third "
               "position:";
  for (int score : scores) { std::cout << " " << score; }
  std::cout << "\n";

  return 0;
}