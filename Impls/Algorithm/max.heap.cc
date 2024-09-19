
#include <iostream>
#include <vector>

class max_heap {
private:
  std::vector<int> _vec;
  size_t _size{0};


public:
  max_heap() {
    //! the element in heap begins at index 1, 
    //! index 0 is for placeholder
    _vec.push_back(0);
  };

  max_heap(std::initializer_list<int> nums) {
    _size = nums.size() + 1;
    _vec.push_back(0);
    for (auto num : nums) {
      _vec.push_back(num);
    }

    for (size_t i = _size / 2; i >= 1; --i) {
      this->heapify_down(i);
    }
  }

  void push(int num) {
    _vec.push_back(num);
    _size += 1;
    this->heapify_up(_size);
  }

  void pop() {
    if (_size > 0) {
      _vec[1] = _vec[_size];
      _vec.pop_back();
      _size -= 1;
      this->heapify_down(1);
    }
  }

  int top() {
    if (_size > 0) {
      return _vec[1];
    } else {
      throw std::out_of_range("Heap is empty");
    }
  }

private:
  void heapify_up(int leaf) {
    while (leaf / 2 >= 1 && _vec[leaf / 2] < _vec[leaf]) {
      size_t parent = leaf / 2;
      std::swap(_vec[parent], _vec[leaf]);
      leaf = parent;
    }
  }

  void heapify_down(int root) {
    while (size_t(2 * root) <= _size) {
      size_t child = 2 * root;
      if (child + 1 <= _size && _vec[child + 1] > _vec[child])
        child += 1;
      if (_vec[root] >= _vec[child])
        break;
      std::swap(_vec[root], _vec[child]);
      root = child;
    }
  }
};

int main() {
  max_heap heap{1, 2, 3, 4, 5, 8, 7, 6};

  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
}
