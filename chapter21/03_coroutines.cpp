#include <algorithm>
#include <coroutine>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

template <typename T> class generator {
public:
  struct promise_type {
    T value;

    auto get_return_object() {
      return generator{handle_type::from_promise(*this)};
    }

    auto initial_suspend() {
      return std::suspend_always{};
    }
    auto final_suspend() noexcept {
      return std::suspend_always{};
    }

    void unhandled_exception() { std::terminate(); }
    void return_void() {}

    auto yield_value(T x) {
      value = x;
      return std::suspend_always{};
    }
  };

  using handle_type = std::coroutine_handle<promise_type>;

  generator(handle_type h) : m_handle(h) {}
  generator(const generator &) = delete;
  generator(generator &&o) noexcept
      : m_handle(std::exchange(o.m_handle, {})) {}

  ~generator() {
    if (m_handle) m_handle.destroy();
  }

  bool next() {
    m_handle.resume();
    return !m_handle.done();
  }

  T value() const { return m_handle.promise().value; }

private:
  handle_type m_handle;
};

generator<int> generate_numbers(int start, int end) {
  for (int i = start; i <= end; ++i) { co_yield i; }
}

int main() {
  std::vector<int> numbers;

  auto gen = generate_numbers(1, 10);
  while (gen.next()) { numbers.push_back(gen.value()); }

  std::vector<int> evenNumbers;
  std::ranges::copy_if(numbers,
                       std::back_inserter(evenNumbers),
                       [](int n) { return n % 2 == 0; });

  const auto transformed =
      evenNumbers |
      std::views::transform([](int n) { return n * 2; });

  for (int n : transformed) { std::cout << n << " "; }

  return 0;
}