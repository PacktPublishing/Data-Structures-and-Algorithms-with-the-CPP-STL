#include <iostream>
#include <string>

class Product {
public:
  std::string name;
  double price;

  Product(const std::string &n, double p)
      : name(n), price(p) {}

  // Overloading the addition operator (+) to combine
  // prices
  Product operator+(const Product &other) const {
    return Product(name + " and " + other.name,
                   price + other.price);
  }

  // Overloading the less than operator (<) to compare
  // prices
  bool operator<(const Product &other) const {
    return price < other.price;
  }

  // Overloading the assignment operator (=) to copy
  // products
  Product &operator=(const Product &other) {
    if (this == &other) { return *this; }

    name = other.name;
    price = other.price;
    return *this;
  }

  // Overloading the compound assignment operator (+=) to
  // add prices
  Product &operator+=(const Product &other) {
    price += other.price;
    return *this;
  }
};

int main() {
  Product widget("Widget", 25.99);
  Product gadget("Gadget", 19.95);

  // Using the overloaded operators
  Product combinedProduct = widget + gadget;

  // Using the compound assignment operator
  widget += gadget;

  bool widgetIsCheaper = widget < gadget;
  bool gadgetIsCheaper = gadget < widget;

  std::cout << "Combined Product: " << combinedProduct.name
            << " ($" << combinedProduct.price << ")"
            << "\n";

  std::cout << "Is Widget cheaper than Gadget? "
            << (widgetIsCheaper ? "Yes" : "No") << "\n";

  std::cout << "Is Gadget cheaper than Widget? "
            << (gadgetIsCheaper ? "Yes" : "No") << "\n";

  std::cout << "Updated widget: " << widget.name << " ($"
            << widget.price << ")"
            << "\n";

  return 0;
}