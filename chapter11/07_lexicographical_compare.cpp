#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<char> seq1 = {'a', 'b', 'c'};
  std::vector<char> seq2 = {'a', 'b', 'd'};
  std::vector<char> seq3 = {'a', 'b', 'c', 'd'};

  if (std::lexicographical_compare(
          seq1.begin(), seq1.end(), seq2.begin(),
          seq2.end())) {
    std::cout << "Sequence 1 is lexicographically less "
                 "than Sequence 2"
              << "\n";
  } else {
    std::cout
        << "Sequence 1 is not lexicographically less "
           "than Sequence 2"
        << "\n";
  }

  if (std::lexicographical_compare(
          seq1.begin(), seq1.end(), seq3.begin(),
          seq3.end())) {
    std::cout << "Sequence 1 is lexicographically less "
                 "than Sequence 3"
              << "\n";
  } else {
    std::cout
        << "Sequence 1 is not lexicographically less "
           "than Sequence 3"
        << "\n";
  }

  // For strings
  std::string str1 = "apple";
  std::string str2 = "banana";

  if (std::lexicographical_compare(
          str1.begin(), str1.end(), str2.begin(),
          str2.end())) {
    std::cout << "String 1 (apple) is lexicographically "
                 "less than String 2 (banana)"
              << "\n";
  } else {
    std::cout << "String 1 (apple) is not "
                 "lexicographically less "
                 "than String 2 (banana)"
              << "\n";
  }

  return 0;
}