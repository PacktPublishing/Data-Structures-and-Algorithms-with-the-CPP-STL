#include <iostream>
#include <string>
#include <unordered_map>

class Person {
public:
  Person(const std::string &n, int a) : name(n), age(a) {}

  std::string getName() const { return name; }
  int getAge() const { return age; }

  bool operator==(const Person &other) const {
    return name == other.name && age == other.age;
  }

private:
  std::string name;
  int age{0};
};

struct PersonHash {
  std::size_t operator()(const Person &person) const {
    // Combine the hash values of name and age using XOR
    std::size_t nameHash =
        std::hash<std::string>()(person.getName());

    std::size_t ageHash =
        std::hash<int>()(person.getAge());

    return nameHash ^ ageHash;
  }
};

int main() {
  std::unordered_map<Person, std::string, PersonHash>
      personMap;

  // Insert Person objects into the map
  Person person1("Alice", 30);
  Person person2("Bob", 25);

  personMap[person1] = "Engineer";
  personMap[person2] = "Designer";

  // Access values using custom Person objects
  std::cout << "Alice's profession: " << personMap[person1]
            << "\n";

  return 0;
}