
#include <coroutine>
#include <iostream>

struct Generator {
  struct promise_type {
    int current_value;
    std::suspend_always yield_value(int value) {
      current_value = value;
      return {};
    }
    Generator get_return_object() {
      return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() { std::exit(1); }
  };

  std::coroutine_handle<promise_type> handle;

  Generator(std::coroutine_handle<promise_type> h) : handle(h) {}
  ~Generator() { handle.destroy(); }

  bool next() {
    handle.resume();
    return !handle.done();
  }

  int value() {
    return handle.promise().current_value;
  }
};

Generator counter() {
  for (int i = 0; i < 3; ++i)
    co_yield i;
}

int main() {
  auto gen = counter();
  while (gen.next()) {
    std::cout << gen.value() << std::endl;
  }
}
