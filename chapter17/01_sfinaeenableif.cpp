#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

// Function Template
template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// Variadic Template
template <typename... Args> void print(Args... args) {

  (std::cout << ... << args) << '\n';
}

// SFINAE with std::enable_if
template <typename T, typename std::enable_if<
                          std::is_integral<T>::value>::type
                          * = nullptr>
void process(T t) {
  std::cout << "Processing integral: " << t << '\n';
}

template <typename T,
          typename std::enable_if<std::is_floating_point<
              T>::value>::type * = nullptr>
void process(T t) {
  std::cout << "Processing floating point: " << t << '\n';
}

// SFINAE for STL containers
template <
    typename T,
    typename std::enable_if<std::is_same<
        T, std::vector<int>>::value>::type * = nullptr>
void processContainer(T &t) {
  std::cout << "Processing vector: ";
  for (const auto &i : t) { std::cout << i << ' '; }

  std::cout << '\n';
}

template <
    typename T,
    typename std::enable_if<std::is_same<
        T, std::map<int, int>>::value>::type * = nullptr>
void processContainer(T &t) {
  std::cout << "Processing map: ";
  for (const auto &[key, value] : t) {
    std::cout << "{" << key << ": " << value << "} ";
  }

  std::cout << '\n';
}

int main() {
  // Function Template
  int a = 5, b = 10;
  swap(a, b);
  std::cout << "Swapped values: " << a << ", " << b
            << '\n';

  // Variadic Template
  print("Hello", " ", "World", "!");

  // SFINAE with std::enable_if
  process(10);
  process(3.14);

  // SFINAE for STL containers
  std::vector<int> vec = {1, 2, 3, 4, 5};
  processContainer(vec);

  std::map<int, int> map = {{1, 2}, {3, 4}, {5, 6}};
  processContainer(map);

  return 0;
}
