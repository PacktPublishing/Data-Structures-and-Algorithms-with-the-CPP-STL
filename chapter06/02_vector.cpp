#include <algorithm>
#include <iostream>
#include <vector>

class Employee {
public:
  Employee(int _id, const std::string &_name)
      : id(_id), name(_name) {}

  int getId() const { return id; }
  const std::string &getName() const { return name; }

  void setName(const std::string &newName) {
    name = newName;
  }

private:
  int id{0};
  std::string name;
};

int main() {
  std::vector<Employee> employees;

  employees.reserve(5);
  employees.emplace_back(1, "Lisa");
  employees.emplace_back(2, "Corbin");
  employees.emplace_back(3, "Aaron");
  employees.emplace_back(4, "Amanda");
  employees.emplace_back(5, "Regan");

  for (const auto &emp : employees) {
    std::cout << "ID: " << emp.getId()
              << ", Name: " << emp.getName() << "\n";
  }

  auto it = std::find_if(
      employees.begin(), employees.end(),
      [](const Employee &e) { return e.getId() == 3; });

  if (it != employees.end()) { it->setName("Chuck"); }

  std::cout << "\nAfter Modification:\n";
  for (const auto &emp : employees) {
    std::cout << "ID: " << emp.getId()
              << ", Name: " << emp.getName() << "\n";
  }

  employees.erase(std::remove_if(employees.begin(),
                                 employees.end(),
                                 [](const Employee &e) {
                                   return e.getId() == 2;
                                 }),
                  employees.end());

  std::cout << "\nAfter Removal:\n";

  for (const auto &emp : employees) {
    std::cout << "ID: " << emp.getId()
              << ", Name: " << emp.getName() << "\n";
  }

  return 0;
}