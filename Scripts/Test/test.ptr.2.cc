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



struct control_block {
  size_t _ref_cnt;
  size_t _weak_ref_cnt;

  control_block() : _ref_cnt(1), _weak_ref_cnt(0) { }
};


//! @brief my shared ptr //////////////////////////////////////////
//! 
template<typename T>
class shared_ptr {
private:
  T* _ptr;
  control_block* _ctrl_block;

public:
  explicit shared_ptr(T* p = nullptr)
  : _ptr(p), _ctrl_block(new control_block());

  shared_ptr(const shared_ptr& other) 
  : _ptr(other._ptr), _ctrl_block(other._ctrl_block) {
    ++(_ctrl_block->_ref_cnt);
  }

  shared_ptr& operator=(const shared_ptr& other) {
    if (this == &other) return *this;

    if (--(_ctrl_block->_ref_cnt) == 0) {
      delete _ptr;
      delete _ctrl_block;
    }

    _ptr = other._ptr;
    _ctrl_block = other._ctrl_block;
    ++(_ctrl_block->_ref_cnt)
    return *this;
  }

  shared_ptr(shared_ptr&& other) noexcept 
  : _ptr(other._ptr), _ctrl_block(other._ctrl_block) {
    other._ptr = nullptr;
    other._ctrl_block = nullptr;
  }

  shared_ptr& operator=(shared_ptr&& other) noexcept {
    if (this == &other) return *this;

    if (--(_ctrl_block->_ref_cnt) == 0) {
      delete _ptr;
      delete _ctrl_block;
    }

    _ptr = other._ptr;
    _ctrl_block = other._ctrl_block;
    other._ptr = nullptr;
    other._ctrl_block = nullptr;
    return *this;
  }

  shared_ptr& operator=(unique_ptr&& other) noexcept {
    if (this == &other) return *this;

    if (--(_ctrl_block->_ref_cnt) == 0) {
      delete _ptr;
      delete _ctrl_block;
    }

    _ptr = other.release();
    _ctrl_block = new control_block();
    return *this;
  }

  ~shared_ptr() {
    if (_ctrl_block && --(_ctrl_block->_ref_cnt) == 0) {
      delete _ptr;
      delete _ctrl_block;
    }
  }

  //! @accessor {
  
  T* get() const {
    return _ptr;
  }
  
  int use_count() const {
    return _ctrl_block->_ref_cnt;
  }

  void reset(T* p = nullptr) {
    if (--(_ctrl_block->_ref_cnt) == 0) {
      delete _ptr;
      delete _ctrl_block;
    }
    if (p) {
      _ptr = p;
      _ctrl_block = new control_block(1);
    } else {
      _ptr = nullptr;
      _ctrl_block = nullptr;
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

// template<typename T, typename... Args>
// shared_ptr<T> make_shared(Args&&... args) {
//     void* memory = ::operator new(sizeof(control_block) + sizeof(T));
//     control_block* ctrl_block = new (memory) control_block();
//     T* obj = new (static_cast<char*>(memory) + sizeof(ctrol_block)) 
//              T(std::forward<Args>(args)...);
//     return MySharedPtr<T>(obj, ctrl_block);
// }

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

  std::weak_ptr<std::vector<int>> ppp = stdPtr;
  
}

