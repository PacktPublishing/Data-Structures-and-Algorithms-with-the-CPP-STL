#include <iostream>
#include <sstream>
#include <stack>
#include <string>

double evaluateRPN(const std::string &expression) {
  std::stack<double> s;
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    if (token == "+" || token == "-" || token == "*" ||
        token == "/") {
      if (s.size() < 2) {
        throw std::runtime_error("Invalid RPN expression");
      }

      double b = s.top();
      s.pop();
      double a = s.top();
      s.pop();

      if (token == "+") {
        s.push(a + b);
      } else if (token == "-") {
        s.push(a - b);
      } else if (token == "*") {
        s.push(a * b);
      } else if (token == "/") {
        if (b == 0.0) {
          throw std::runtime_error("Division by zero");
        }
        s.push(a / b);
      }
    } else {
      s.push(std::stod(token));
    }
  }

  if (s.size() != 1) {
    throw std::runtime_error("Invalid RPN expression");
  }

  return s.top();
}

int main() {
  try {
    // Evaluate RPN expressions
    std::cout << "46 2 + = " << evaluateRPN("46 2 +")
              << "\n"; // 48
    std::cout << "5 1 2 + 4 * + 3 - = "
              << evaluateRPN("5 1 2 + 4 * + 3 -")
              << "\n"; // -14
    std::cout << "3 4 5 * - = " << evaluateRPN("3 4 5 * -")
              << "\n"; // -17
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}