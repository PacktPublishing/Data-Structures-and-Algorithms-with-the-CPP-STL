#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {

  std::vector<std::string> words = {"Hello", ", ", "world",
                                    "!"};

  std::string concatenated = std::accumulate(
      words.begin(), words.end(), std::string(""),
      [](const std::string &x, const std::string &y) {
        return x + y;
      });

  std::cout << "Concatenated string: " << concatenated
            << std::endl;

  return 0;
}
