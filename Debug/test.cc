#include <arpa/inet.h>
#include <cstdint>

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>


class A {
private:
  int _size;
  int* _vec;

public:
  A(int size) {
    _size = size;
    _vec = new int[size];
  }

  ~A() {
    delete[] _vec;
    _vec = nullptr;
  }

  // 浅拷贝构造函数
  A(const A& other) {
    _size = other._size;
    _vec = other._vec;
  }

  // 深拷贝构造函数
  A(const A& other) {
    _size = other._size;
    _vec = new int[_size];
    for (int i = 0; i < _size; ++i) {
      _vec[i] = other._vec[i];
    }
  }

  A& operator=(const A& other) {
    if (this == &other)
      return *this;

    if (_vec) {
      delete[] _vec;
    }

    _size = other._size;
    _vec = other._vec;
    return *this;
  }

};


int main() {
  std::unordered_map<std::string, std::string> u_map;
  std::map<std::string, std::string> map;

  // 插入 key-value
  map["panda"] = "17688054570";
  map["random"] = "12148912892";

  // 通过 key 访问 value
  if (map.count("panda") != 0) // 如果 "panda" 这个 key 在哈希表中
    std::cout << map["panda"] << std::endl; // 则访问并输出
  else
    std::cout << "panda not found in the map!" << std::endl;



  std::vector<int> vec{1, 2, 3, 4, 5};

  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i];

  for (auto it = vec.begin(); it != vec.end(); it++)
    std::cout << *it;
}
