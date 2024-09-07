#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <iterator>

namespace my
{

template<typename T>
constexpr typename std::remove_reference<T>::type&& 
move(T&& arg) noexcept 
{
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}

//! @brief my unique ptr //////////////////////////////////////////
//! 
template<typename T>
class unique_ptr {
private:
  T* _ptr;

public:
  explicit unique_ptr(T* p = nullptr) : _ptr(p) { }

  unique_ptr(const unique_ptr&) = delete;
  unique_ptr& operator=(const unique_ptr&) = delete;

  unique_ptr(unique_ptr&& other) noexcept : _ptr(other._ptr) {
    other._ptr = nullptr;
  };

  unique_ptr& operator=(unique_ptr&& other) noexcept {
    if (this == &other) return *this;
    
    delete _ptr;

    _ptr = other._ptr;
    other._ptr = nullptr;
    return *this;
  };

  ~unique_ptr() {
    delete _ptr;
  }

  //! @accessor {
  
  T* get() const {
    return _ptr;
  }

  T* release() const {
    auto p = _ptr;
    _ptr = nullptr;
    return p;
  }

  void reset(T* p = nullptr) {
    delete _ptr;
    _ptr = p;
  }

  T& operator*() const {
    return *_ptr;
  }

  T* operator->() const {
    return _ptr;
  }
  
  //! @}
};


//! @brief my shared ptr //////////////////////////////////////////
//! 
template<typename T>
class shared_ptr {
private:
  T* _ptr;
  int* _ref_cnt;

public:
  explicit shared_ptr(T*p = nullptr)
   : _ptr(p), _ref_cnt(new int(1)) { }

  shared_ptr(const shared_ptr& other) 
  : _ptr(other._ptr), _ref_cnt(other._ref_cnt) {
    ++(*_ref_cnt);
  }

  shared_ptr& operator=(const shared_ptr& other) {
    if (this == &other) return *this;

    if (--(*_ref_cnt) == 0) {
      delete _ptr;
      delete _ref_cnt;
    }

    _ptr = other._ptr;
    _ref_cnt = other._ref_cnt;
    ++(*_ref_cnt);
    return *this;
  }

  shared_ptr(shared_ptr&& other) noexcept 
  : _ptr(other._ptr), _ref_cnt(other._ref_cnt) {
    other._ptr = nullptr;
    other._ref_cnt = nullptr;
  }

  shared_ptr& operator=(shared_ptr&& other) noexcept {
    if (this == &other) return *this;

    if (--(*_ref_cnt) == 0) {
      delete _ptr;
      delete _ref_cnt;
    }

    _ptr = other._ptr;
    _ref_cnt = other._ref_cnt;
    other._ptr = nullptr;
    other._ref_cnt = nullptr;
    return *this;
  }

  shared_ptr& operator=(unique_ptr&& other) noexcept {
    if (this == &other) return *this;

    if (--(*_ref_cnt) == 0) {
      delete _ptr;
      delete _ref_cnt;
    }

    _ptr = other.release();
    _ref_cnt = new int (1);
    return *this;
  }

  ~shared_ptr() {
    if (_ref_cnt && --(*_ref_cnt) == 0) {
      delete _ptr;
      delete _ref_cnt;
    }
  }

  //! @accessor {
  
  T* get() const {
    return _ptr;
  }
  
  int use_count() const {
    return *_ref_cnt;
  }

  void reset(T* p = nullptr) {
    if (--(*_ref_cnt) == 0) {
      delete _ptr;
      delete _ref_cnt;
    }
    if (p) {
      _ptr = p;
      _ref_cnt = new int(1);
    } else {
      _ptr = nullptr;
      _ref_cnt = nullptr;
    }
  }

  T& operator*() const {
    return *_ptr;
  }

  T* operator->() const {
    return _ptr;
  }
  
  //! @}
};

} // namespace my


int main() {
  // my test
  auto ptr1 = my::unique_ptr<std::vector<int>>(
    new std::vector<int>({3, 2, 1}));

  auto ptr2 = std::move(ptr1);
  auto tmp = std::next(ptr2->rbegin());
  std::cout << *tmp << std::endl;

  // std test
  auto stdPtr = std::shared_ptr<std::vector<int>>(
    new std::vector<int>({3, 2, 1}));

  stdPtr.reset(new std::vector<int>({4, 2, 4}));
}

