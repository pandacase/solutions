#include <iostream>
#include <cstring>
#include <string>
#include <utility>

template<typename T>
constexpr typename std::remove_reference<T>::type&& move(T&& arg) noexcept {
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}


class MyString {
private:
  char* data;
  size_t size;

public:
  //! @brief Construct a new My String object
  //! 
  MyString() : data{new char[1]{'\0'}}, size{0} {}

  //! @brief Construct a new My String object from `const char*`
  //! 
  MyString(const char* str) {
    if (str) {
      size = std::strlen(str);
      data = new char[size + 1];
      std::strcpy(data, str);
    } else {
      MyString();
    }
  }

  //! @brief Construct a new My String object from copy
  //! 
  MyString(const MyString& other) {
    size = other.size;
    data = new char[size + 1];
    std::strcpy(data, other.data);
  }

  //! @brief Construct a new My String object from move
  //! 
  MyString(MyString&& other) noexcept 
    : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
  }

  //! @brief Copy assignment operator
  //! 
  MyString& operator=(const MyString& other) {
    if (this == &other) return *this;

    delete[] data;

    size = other.size;
    data = new char[size + 1];
    std::strcpy(data, other.data);
  
    return *this;
  }

  //! @brief Move assignment operpator
  //! 
  MyString& operator=(MyString&& other) noexcept {
    if (this == &other) return *this;

    delete[] data;

    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;

    return *this;
  }

  // Destructor
  ~MyString() {
    delete[] data;
  }

  void print() const {
    if (size)
      std::cout << data << std::endl;
    else
      std::cerr << "[!] No string." << std::endl;
  }

};


int 
main()
{
  MyString str1("hello, world");
  MyString str2 = str1;
  MyString str3("Temporary");

  str3 = str2;
  str3.print();

  MyString str4 = move(str1);
  str4.print();
  str1.print();

  str3 = move(str4);
  str3.print();
  str4.print();

  return 0;
}