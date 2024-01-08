#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age{0};

  Person(std::string n, int a) : name(n), age(a) {}

  friend std::ostream &operator<<(std::ostream &os,
                                  const Person &p) {
    os << p.name << " (" << p.age << ")";
    return os;
  }
};

int main() {
  std::vector<Person> people = {Person("Regan", 30),
                                Person("Lisa", 40),
                                Person("Corbin", 45)};

  auto compareByName = [](const Person &a,
                          const Person &b) {
    return a.name < b.name;
  };

  std::sort(people.begin(), people.end(), compareByName);

  std::cout << "Sorted by name:\n";
  for (const auto &p : people) { std::cout << p << "\n"; }

  std::sort(people.begin(), people.end(),
            [](const Person &a, const Person &b) {
              return a.age < b.age;
            });

  std::cout << "\nSorted by age:\n";
  for (const auto &p : people) { std::cout << p << "\n"; }

  return 0;
}