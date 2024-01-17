#include <algorithm>
#include <iostream>
#include <vector>

// Define a Strategy interface
class Strategy {
public:
  virtual void
  execute(const std::vector<int> &data) const = 0;
};

// Define a Concrete Strategy that uses std::for_each and a
// lambda function
class ForEachStrategy : public Strategy {
public:
  void
  execute(const std::vector<int> &data) const override {
    std::for_each(data.begin(), data.end(), [](int value) {
      std::cout << "ForEachStrategy: " << value << "\n";
    });
  }
};

// Define a Concrete Strategy that uses std::transform and
// a lambda function
class TransformStrategy : public Strategy {
public:
  void
  execute(const std::vector<int> &data) const override {
    std::vector<int> transformedData(data.size());
    std::transform(data.begin(), data.end(),
                   transformedData.begin(),
                   [](int value) { return value * 2; });

    for (const auto &value : transformedData) {
      std::cout << "TransformStrategy: " << value << "\n";
    }
  }
};

// Define a Context that uses a Strategy
class Context {
public:
  Context(Strategy *strategy) : strategy(strategy) {}

  void setStrategy(Strategy *newStrategy) {
    strategy = newStrategy;
  }

  void executeStrategy(const std::vector<int> &data) {
    strategy->execute(data);
  }

private:
  Strategy *strategy;
};

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};

  ForEachStrategy forEachStrategy;
  TransformStrategy transformStrategy;

  Context context(&forEachStrategy);
  context.executeStrategy(data);
  context.setStrategy(&transformStrategy);
  context.executeStrategy(data);
  return 0;
}
