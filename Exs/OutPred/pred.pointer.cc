
#include <iostream>

int main() {
  int value = 0x1234;

  // 如何使用一个 char* 指针指向 int*
  char* ptr = reinterpret_cast<char*>(&value);

  // 在小端系统中以下各输出
  std::cout << "value = 0x1234" << std::endl;
  std::cout << int(*(ptr+0)) << std::endl;
  std::cout << int(*(ptr+1)) << std::endl;
  std::cout << int(*(ptr+2)) << std::endl;
  std::cout << int(*(ptr+3)) << std::endl;
}
