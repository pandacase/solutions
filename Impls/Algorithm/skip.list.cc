#include <iostream>
#include <vector>
#include <random>
#include <limits>

class skip_list_node {
public:
  int _value;
  std::vector<skip_list_node*> _forward;

  skip_list_node(int value, int level)
   : _value(value), _forward(level, nullptr) {}
};

class skip_list {
private:
  static const int _MAX_LEVEL = 16;
  //! Probability used for generate random level
  static constexpr float _P = 0.5;

  skip_list_node* _head;
  int _level{1};
  std::default_random_engine _generator{std::random_device{}()};
  std::uniform_real_distribution<float> _distribution{0.0, 1.0};

private:
  //! @brief Generate a random level number
  //! 
  int random_level() {
    int lvl = 1;
    while (_distribution(_generator) < _P && lvl < _MAX_LEVEL) {
      lvl++;
    }
    return lvl;
  }

public:
  skip_list() {
    _head = new skip_list_node(0, _MAX_LEVEL);
  }

  ~skip_list() {
    auto curr = _head;
    while (curr) {
      auto next = curr->_forward[0];
      delete curr;
      curr = next;
    }
  }

  //! @brief Find a node with value
  //! 
  //! @return pointer to the node
  skip_list_node* find(int value) {
    auto curr = _head;
    for (int i = _level - 1; i >= 0; --i) {
      while (curr->_forward[i] && curr->_forward[i]->_value < value) {
        curr = curr->_forward[i];
      }
    }
    curr = curr->_forward[0];
    if (curr && curr->_value == value)
      return curr;
    return nullptr;
  }

public:
  //! @brief Insert a new node with the value into skip list
  //! 
  void insert(int value) {
    std::vector<skip_list_node*> update{_MAX_LEVEL};
    auto curr = _head;
    for (int i = _level - 1; i >= 0; --i) {
      while (curr->_forward[i] && curr->_forward[i]->_value < value) {
        curr = curr->_forward[i];
      }
      update[i] = curr;
    }

    int new_level = random_level();
    if (new_level > _level) {
      for (int i = _level; i < new_level; ++i) {
        update[i] = _head;
      }
      _level = new_level;
    }

    auto new_node = new skip_list_node(value, new_level);
    for (int i = 0; i < new_level; ++i) {
      new_node->_forward[i] = update[i]->_forward[i];
      update[i]->_forward[i] = new_node;
    }
  }

  //! @brief Earase the node with the value from skip list
  //! 
  void erase(int value) {
    std::vector<skip_list_node*> update{_MAX_LEVEL};
    auto curr = _head;
    for (int i = _level - 1; i >= 0; --i) {
      while (curr->_forward[i] && curr->_forward[i]->_value < value) {
        curr = curr->_forward[i];
      }
      update[i] = curr;
    }

    curr = curr->_forward[0];
    if (curr && curr->_value == value) {
      for (int i = _level - 1; i >= 0; --i) {
        if (update[i]->_forward[i] == curr) {
          update[i]->_forward[i] = curr->_forward[i];
        }
      }
      delete curr;

      while (_level > 1 && _head->_forward[_level - 1] == nullptr) {
        --_level;
      }
    } else {
      std::cerr << "No node found." << std::endl;
    }
  }

  //! @brief Print the whole skip list level by level
  //! 
  void print() {
    for (int i = _level - 1; i >= 0; --i) {
      auto curr = _head->_forward[i];
      std::cout << "⭐ Level " << i + 1 << ": ";
      while (curr) {
        std::cout << curr->_value << " ";
        curr = curr->_forward[i];
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  skip_list sl = skip_list();

  for (int i = 0; i < 100; ++i) {
    if (i % 3 == 1)
      sl.insert(i);
  }

  sl.print();
  
  sl.erase(16);

  std::cout << "-----------------------------------" << std::endl;
  sl.print();
}