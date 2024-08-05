#include <vector>
#include <iostream>
#include <random>
#include <unordered_map>

//! @details 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
//! 
class RandomizedSet {
private:
  std::vector<int> vec;
  std::unordered_map<int, int> map;

public:
  //! @brief  初始化 RandomizedSet 对象
  //!
  RandomizedSet() : vec(), map() { }
  
  //! @brief 当元素 val 不存在时，向集合中插入该项，返回 true
  //! 否则，返回 false。
  //!
  bool insert(int val) {
    if (map.count(val)) return false;
    else {
      vec.push_back(val);
      map[val] = vec.size() - 1;
      return true;
    }
  }
  
  //! @brief 当元素 val 存在时，从集合中移除该项，并返回 true
  //! 否则，返回 false。
  //!
  bool remove(int val) {
    if (map.count(val)) {
      map[vec[vec.size() - 1]] = map[val];
      std::swap(vec[map[val]], vec[vec.size() - 1]);
      vec.pop_back();
      map.erase(val);
      return true;
    } else return false;
  }
  
  //! @brief 随机返回现有集合中的一项，每个元素应该有相同的概率被返回。
  //!（测试用例保证调用此方法时集合中至少存在一个元素）。
  //!
  int getRandom() {
    int offset = rand() % vec.size();
    return vec[offset];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
  RandomizedSet set;
  std::cout << set.insert(0) << std::endl;    // true -> [0]
  std::cout << set.insert(1) << std::endl;    // true -> [0, 1]
  std::cout << set.remove(0) << std::endl;    // true -> [1]
  std::cout << set.insert(2) << std::endl;    // true -> [1, 2]
  std::cout << set.remove(1) << std::endl;    // true -> [2]
  std::cout << set.getRandom() << std::endl;  // 2
}