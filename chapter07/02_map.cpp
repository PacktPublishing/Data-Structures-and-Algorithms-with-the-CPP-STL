#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> ageMap = {
      {"Lisa", 25}, {"Corbin", 30}, {"Aaron", 22}};

  ageMap["Kristan"] = 28;
  ageMap.insert_or_assign("Lisa", 26);

  if (ageMap.find("Corbin") != ageMap.end()) {
    std::cout << "Corbin exists in the map.\n";
  }

  ageMap["Aaron"] += 1;

  std::cout << "Age records:\n";
  for (const auto &[name, age] : ageMap) {
    std::cout << name << ": " << age << '\n';
  }

  ageMap.erase("Corbin");

  if (ageMap.count("Regan") == 0) {
    std::cout << "Regan does not exist in the map.\n";
  }

  std::map<std::string, int,
           bool (*)(const std::string &,
                    const std::string &)>
      customOrderMap{[](const std::string &lhs,
                        const std::string &rhs) {
        return lhs > rhs; // reverse lexicographic order
      }};

  customOrderMap["Lisa"] = 25;
  customOrderMap["Corbin"] = 30;
  customOrderMap["Aaron"] = 22;

  std::cout << "Custom ordered map:\n";
  for (const auto &[name, age] : customOrderMap) {
    std::cout << name << ": " << age << '\n';
  }

  return 0;
}