#include <forward_list>
#include <iostream>
#include <vector>

template <typename KeyType, typename ValueType>
class ChainedHashTable {
public:
  ChainedHashTable(size_t capacity) : capacity(capacity) {
    table.resize(capacity);
  }

  bool get(const KeyType &key, ValueType &value) const {
    const auto &list = table[hash(key)];
    for (const auto &bucket : list) {
      if (bucket.key == key) {
        value = bucket.value;
        return true;
      }
    }
    return false;
  }

  void put(const KeyType &key, const ValueType &value) {
    auto &list = table[hash(key)];
    for (auto &bucket : list) {
      if (bucket.key == key) {
        bucket.value = value;
        return;
      }
    }
    list.emplace_front(key, value);
  }

  bool remove(const KeyType &key) {
    auto &list = table[hash(key)];
    return list.remove_if([&](const Bucket &bucket) {
      return bucket.key == key;
    });
  }

private:
  struct Bucket {
    KeyType key;
    ValueType value;
    Bucket(KeyType k, ValueType v) : key(k), value(v) {}
  };

  std::vector<std::forward_list<Bucket>> table;
  size_t capacity;
  size_t hash(const KeyType &key) const {
    return std::hash<KeyType>{}(key) % capacity;
  }
};

int main() {
  ChainedHashTable<std::string, int> hashTable(10);

  hashTable.put("apple", 10);
  hashTable.put("banana", 20);
  hashTable.put("cherry", 30);

  int value;
  if (hashTable.get("apple", value)) {
    std::cout << "apple: " << value << "\n";
  }

  if (hashTable.get("banana", value)) {
    std::cout << "banana: " << value << "\n";
  }

  hashTable.remove("banana");

  if (!hashTable.get("banana", value)) {
    std::cout << "banana not found!\n";
  }

  return 0;
}