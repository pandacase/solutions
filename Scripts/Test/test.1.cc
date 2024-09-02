
#include <bits/stdc++.h>

template <typename T>
concept Number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Number T>
T add(T a, T b) { return a + b; };


class Base {
public:
    virtual void show() {
        std::cout << "Base class show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show" << std::endl;
    }
};


int 
main()
{
  //! 1. emplace test
  // std::vector<std::string> vec;
  // vec.push_back("hello");
  // std::string str("hello");
  // vec.push_back(str);
  // vec.emplace_back("hello");

  //! 2. lambda test
  // auto myLambda = [](int x) { return x + 1; };
  // std::sort(vec.begin(), vec.end(), [](std::string a, std::string b) {
  //   return a.size() < b.size();
  // });

  //! virtual func test
  Base* b = new Derived();
  b->show();  // 输出: Derived class show
  delete b;
}

