#include <concepts>
#include <iostream>
#include <vector>

template <typename T>
concept Drawable = requires(T obj) {
  { obj.draw() } -> std::convertible_to<void>;
};

class Circle {
public:
  void draw() const { std::cout << "Drawing a circle.\n"; }
};

class Square {
public:
  // No draw() member function
};

template <Drawable T> void drawShape(const T &shape) {
  shape.draw();
}

int main() {
  Circle circle;
  Square square;

  drawShape(circle);

  // Uncommenting the line below would result in
  // 'drawShape': no matching overloaded function found:
  // drawShape(square);

  return 0;
}
