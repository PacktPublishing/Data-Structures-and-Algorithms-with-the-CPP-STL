#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string s = "Hello, C++ World!";

  std::cout << "Size: " << s.size() << "\n";
  std::cout << "First char: " << s[0] << "\n";

  std::string greet = "Hello";
  std::string target = "World";
  std::string combined = greet + ", " + target + "!";
  std::cout << "Combined: " << combined << "\n";

  if (s.find("C++") != std::string::npos) {
    std::cout << "String contains 'C++'\n";
  }

  std::transform(
      s.begin(), s.end(), s.begin(),
      [](unsigned char c) { return std::toupper(c); });
  std::cout << "Uppercase: " << s << "\n";

  std::transform(
      s.begin(), s.end(), s.begin(),
      [](unsigned char c) { return std::tolower(c); });
  std::cout << "Lowercase: " << s << "\n";

  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  std::cout << "Without spaces: " << s << "\n";

  std::string first = "apple";
  std::string second = "banana";

  if (first < second) {
    std::cout << first << " comes before " << second
              << "\n";
  }

  int number = 2112;
  std::string numStr = std::to_string(number);
  std::cout << "Number as string: " << numStr << "\n";

  int convertedBack = std::stoi(numStr);
  std::cout << "String back to number: " << convertedBack
            << "\n";

  return 0;
}