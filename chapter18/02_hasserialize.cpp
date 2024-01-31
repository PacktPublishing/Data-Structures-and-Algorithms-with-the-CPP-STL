#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// Define a type trait to check for serialize method
template <typename, typename T>
struct has_serialize : std::false_type {};

template <typename T>
struct has_serialize<
    std::void_t<decltype(std::declval<T>().serialize())>,
    T> : std::true_type {};

template <typename T>
inline constexpr bool has_serialize_v =
    has_serialize<void, T>::value;

class Person {
public:
  std::string name;
  int age{0};
  std::string serialize() const {
    return "Person{name: " + name +
           ", age: " + std::to_string(age) + "}";
  }
};

class Dog {
public:
  std::string name;
  std::string breed;
  // Note: Dog does not have a serialize method
};

template <typename T>
void processCollection(const std::vector<T> &collection) {
  static_assert(has_serialize_v<T>,
                "T must have a serialize() method.");
  for (const auto &item : collection) {
    std::cout << item.serialize() << std::endl;
  }
}

int main() {
  // Valid use, Person has a serialize method
  std::vector<Person> people = {{"Alice", 30},
                                {"Bob", 35}};
  processCollection(people);

  // Compile-time error:
  // std::vector<Dog> dogs = {{"Buddy", "Beagle"}};
  // processCollection(dogs);
}
