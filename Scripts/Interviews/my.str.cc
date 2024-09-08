#include <iostream>
#include <cstring>
#include <string>
#include <utility>

namespace my 
{

template<typename T>
constexpr typename std::remove_reference<T>::type&& 
move(T&& arg) noexcept 
{
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}


class string {
private:
  char* _data;
  size_t _size;

public:
  //! @brief Construct a new My String object
  //! 
  string() : _data{new char[1]{'\0'}}, _size{0} {}

  //! @brief Construct a new My String object from `const char*`
  //! 
  string(const char* str) {
    if (str) {
      _size = std::strlen(str);
      _data = new char[_size + 1];
      std::strcpy(_data, str);
    } else {
      string();
    }
  }

  //! @brief Construct a new My String object from copy
  //! 
  string(const string& other) {
    _size = other._size;
    _data = new char[_size + 1];
    std::strcpy(_data, other._data);
  }

  //! @brief Construct a new My String object from move
  //! 
  string(string&& other) noexcept 
    : _data(other._data), _size(other._size) {
    other._data = nullptr;
    other._size = 0;
  }

  //! @brief Copy assignment operator
  //! 
  string& operator=(const string& other) {
    if (this == &other) return *this;

    delete[] _data;

    _size = other._size;
    _data = new char[_size + 1];
    std::strcpy(_data, other._data);
  
    return *this;
  }

  //! @brief Move assignment operpator
  //! 
  string& operator=(string&& other) noexcept {
    if (this == &other) return *this;

    delete[] _data;

    _size = other._size;
    _data = other._data;

    other._size = 0;
    other._data = nullptr;

    return *this;
  }

  // Destructor
  ~string() {
    delete[] _data;
  }

  void print() const {
    if (_size)
      std::cout << _data << std::endl;
    else
      std::cerr << "[!] No string." << std::endl;
  }

};

} // namespace my

int 
main()
{
  my::string str1("hello, world");
  my::string str2 = str1;
  my::string str3("Temporary");

  str3 = str2;
  str3.print();

  my::string str4 = my::move(str1);
  str4.print();
  str1.print();

  str3 = my::move(str4);
  str3.print();
  str4.print();

  return 0;
}