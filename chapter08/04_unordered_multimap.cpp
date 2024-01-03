#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_multimap<std::string, int> grades;

  grades.insert({"Lisa", 85});
  grades.insert({"Corbin", 92});
  grades.insert({"Lisa", 89});
  grades.insert({"Aaron", 76});
  grades.insert({"Corbin", 88});
  grades.insert({"Regan", 91});

  size_t lisaCount = grades.count("Lisa");
  std::cout << "Number of grade entries for Lisa: "
            << lisaCount << '\n';

  auto range = grades.equal_range("Lisa");
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << it->first << " has grade: " << it->second
              << '\n';
  }

  auto lisaGrade = grades.find("Lisa");
  if (lisaGrade != grades.end()) {
    lisaGrade->second = 90; // Updating the grade
  }

  grades.erase("Corbin"); // This will erase all grade
                          // entries for Corbin
  std::cout
      << "Number of grade entries for Corbin after erase: "
      << grades.count("Corbin") << '\n';

  std::cout << "Load factor: " << grades.load_factor()
            << '\n';
  std::cout << "Bucket count: " << grades.bucket_count()
            << '\n';

  grades.rehash(50);
  std::cout << "Bucket count after rehashing: "
            << grades.bucket_count() << '\n';

  for (const auto &entry : grades) {
    std::cout << entry.first
              << " received grade: " << entry.second
              << '\n';
  }

  return 0;
}