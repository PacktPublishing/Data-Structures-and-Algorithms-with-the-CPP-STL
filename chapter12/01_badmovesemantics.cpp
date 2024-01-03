#include <iostream>
#include <vector>

void printVector(const std::vector<int> &vec,
                 const std::string &name) {
  std::cout << name << ": ";
  for (int val : vec) { std::cout << val << " "; }
  std::cout << "\n";
}

int main() {
  std::vector<int> source = {10, 20, 30, 40, 50};

  std::vector<int> destination = std::move(source);

  std::cout
      << "Trying to access the 'source' vector after "
         "moving its data:\n";

  printVector(source, "Source");
  printVector(destination, "Destination");

  source.push_back(60);
  std::cout << "After trying to add data to 'source' "
               "post-move:\n";
  printVector(source, "Source");

  return 0;
}