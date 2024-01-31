#include <functional>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

// Hashing Policy
template <typename Key> struct DefaultHashPolicy {
  std::size_t operator()(const Key &key) const {
    return std::hash<Key>()(key);
  }
};

// Collision Resolution Policy
template <typename Key, typename Value>
struct SeparateChainingPolicy {
  using BucketType = std::list<std::pair<Key, Value>>;
};

// Custom Hash Table
template <typename Key, typename Value,
          typename HashPolicy = DefaultHashPolicy<Key>,
          typename CollisionPolicy =
              SeparateChainingPolicy<Key, Value>>
class CustomHashTable {
private:
  std::vector<typename CollisionPolicy::BucketType> table;
  HashPolicy hashPolicy;
  // ...

public:
  CustomHashTable(size_t size) : table(size) {}
  // ... Implement methods like insert, find, erase
};

int main() {
  // Instantiate custom hash table with default policies
  CustomHashTable<int, std::string> hashTable(10);
  // ... Usage of hashTable
}
