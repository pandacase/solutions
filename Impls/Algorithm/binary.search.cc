
#include <vector>
#include <iostream>

//! @brief 返回 值为 value 的元素所在下标值
//! 
int equal(std::vector<int>& vec, int value) {
  if (vec.empty())
    return -1;

  int low = 0, high = vec.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] > value)
      high = mid - 1;
    else if (vec[mid] < value)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

//! @brief 返回 第一个 值为 value 的元素所在下标值
//! 
int first_equal(std::vector<int>& vec, int value) {
  if (vec.empty())
    return -1;

  int low = 0, high = vec.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] >= value)
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (low < vec.size() && vec[low] == value)
    return low;
  else
    return -1;
}

//! @brief 返回 最后一个 值为 value 的元素所在下标值
//! 
int last_equal(std::vector<int>& vec, int value) {
  if (vec.empty())
    return -1;

  int low = 0, high = vec.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] <= value)
      low = mid + 1;
    else
      high = mid - 1;
  }

  if (low - 1 >= 0 && vec[low - 1] == value)
    return low - 1;
  else
    return -1;
}






int main() {
  std::vector<int> vec{1, 3, 4, 5, 6, 8, 8, 8, 11, 18};

  
}