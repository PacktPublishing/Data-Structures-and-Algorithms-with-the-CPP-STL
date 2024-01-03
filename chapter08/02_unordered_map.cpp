#include <iostream>
#include <unordered_map>

void displayMap(
    const std::unordered_map<std::string, int> &map) {
  for (const auto &[key, value] : map) {
    std::cout << key << ": " << value << '\n';
  }
}

int main() {
  std::unordered_map<std::string, int> ageMap;

  ageMap["Lisa"] = 28;
  ageMap["Corbin"] = 25;
  ageMap["Aaron"] = 30;

  std::cout << "Corbin's age: " << ageMap["Corbin"]
            << '\n';

  if (ageMap.find("Daisy") == ageMap.end()) {
    std::cout << "Daisy not found in the map." << '\n';
  } else {
    std::cout << "Daisy's age: " << ageMap["Daisy"]
              << '\n';
  }

  ageMap["Lisa"] = 29;
  std::cout << "Lisa's updated age: " << ageMap["Lisa"]
            << '\n';

  displayMap(ageMap);

  std::cout << "Load factor: " << ageMap.load_factor()
            << '\n';
  std::cout << "Bucket count: " << ageMap.bucket_count()
            << '\n';

  ageMap.rehash(50);
  std::cout << "Bucket count after rehash: "
            << ageMap.bucket_count() << '\n';

  // Remove an entry
  ageMap.erase("Aaron");
  displayMap(ageMap);

  return 0;
}