#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  Person(const std::string &firstName,
         const std::string &lastName)
      : fullName(firstName + " " + lastName) {}

  const std::string &getName() const { return fullName; }

private:
  std::string fullName;
};

int main() {
  std::vector<Person> people;
  people.emplace_back("John", "Doe");
  people.emplace(people.begin(), "Jane", "Doe");

  for (const auto &person : people) {
    std::cout << person.getName() << "\n";
  }

  return 0;
}