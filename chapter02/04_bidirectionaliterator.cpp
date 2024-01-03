#include <iostream>
#include <list>

int main() {
  std::list<int> numbers = {1, 2, 3, 4, 5};

  std::cout << "Traversing the list forwards:\n";
  for (std::list<int>::iterator it = numbers.begin();
       it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "Traversing the list backwards:\n";
  for (std::list<int>::reverse_iterator rit =
           numbers.rbegin();
       rit != numbers.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << "\n";

  return 0;
}