#include <iostream>
#include <type_traits>

// Create a class that is not inherently printable.
struct NotPrintable
{
  int foo{0};
  int bar{0};
};

// Concept definition using the 'requires' clause
template <typename T>
concept Printable = requires(T t) {
  // Requires that t can be printed to std::cout
  std::cout << t;
};

// Before C++20:
// A Function template that uses SFINAE to implement a
// "Printable concept"
template <typename T,
          typename = typename std::enable_if<std::is_same<
              decltype(std::cout << std::declval<T>()),
              std::ostream &>::value>::type>
void printValueSFINAE(const T &value) {
  std::cout << "Value: " << value << "\n";
}

// After C++20:
// A Function template that uses the Printable concept
template <Printable T> void printValue(const T &value) {
  std::cout << "Value: " << value << "\n";
}

int main() {
  const int num = 42;
  const NotPrintable np;
  const std::string str = "Hello, Concepts!";

  // Using the function template with SFINAE
  printValueSFINAE(num);
  // This line would fail to compile:
  // printValueSFINAE(np);
  printValueSFINAE(str);

  // Using the function template with concepts
  printValue(num);
  // This line would fail to compile
  // printValue(np);
  printValue(str);

  return 0;
}
