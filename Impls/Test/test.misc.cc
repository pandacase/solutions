
#include <bits/stdc++.h>

// 3 ////////////////////////////////////////////////////////////////////////
template <typename T>
concept Number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Number T>
T add(T a, T b) { return a + b; };
// 3 end ////////////////////////////////////////////////////////////////////


// 4 ////////////////////////////////////////////////////////////////////////
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
// 4 end ////////////////////////////////////////////////////////////////////


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

  //! 3. concept test
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.1, 2.2) << std::endl;

  //! 4. virtual func test with GDB
  Base* b = new Derived();
  b->show();  // 输出: Derived class show
  delete b;
}

