
#include <iostream>
#include <mutex>

class Singleton {
public:
  static Singleton& getInstance() {
    //! C++ 11 之后保证了静态遍历的初始化是线程安全的
    //! 而后续也没有加锁，所以这是一个自带的双重检查机制
    static Singleton instance;
    return instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator==(const Singleton&) = delete;

  void showMessage() const {
    std::cout << "Hi." << std::endl;
  }

private:
  Singleton() {
    std::cout << "Construct." << std::endl;
  }
};

int main() {
  auto& ins1 = Singleton::getInstance();
  ins1.showMessage();

  auto& ins2 = Singleton::getInstance();
  ins2.showMessage();

  if (&ins1 == &ins2) {
    std::cout << "Same." << std::endl;
  } else {
    std::cout << "Not same." << std::endl;
  }
}

//////////////////////////////////////////////////////////////

//! @brief 
//! 在 C++ 11 之前的双重检查典型实现如下
//! 
class Singleton_old {
public:
  static Singleton_old* getInstance() {
    if (_instance == nullptr) {
      std::lock_guard<std::mutex> lock(_mutex);
      if (_instance == nullptr) {
        _instance = new Singleton_old();
      }
    } else {
      return _instance;
    }
  }

private:
  Singleton_old() = default;
  static Singleton_old* _instance;
  static std::mutex _mutex;
};
