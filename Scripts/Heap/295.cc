
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 中位数是有序整数列表中的中间值。
//! 如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
//! 请实现 MedianFinder 类。
//! 
//! @details 
//! -105 <= num <= 105
//! 在调用 findMedian 之前，数据结构中至少有一个元素
//! 最多 5 * 104 次调用 addNum 和 findMedian
//! 
//! @example 
//! input:  ["MedianFinder", "addNum", "addNum", "findMedian", 
//!          "addNum", "findMedian"]
//!         [[], [1], [2], [], [3], []]
//! output: [null, null, null, 1.5, null, 2.0]
//! 
//! @note
//! 
class MedianFinder {
public:
  MedianFinder() { }
  
  //! @brief 将数据流中的整数 num 添加到数据结构中。
  //! 
  void addNum(int num) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    _size += 1;
    this->maintain();
  }
  
  //! @brief 返回到目前为止所有元素的中位数(与实际答案相差 10^-5 以内)
  //! 
  double findMedian() {
    if (_size % 2 != 0) {
      return double(maxHeap.top());
    } else {
      return double(maxHeap.top() + minHeap.top()) / 2;
    }
  }

private:
  //! @brief 维持 2 个堆的数量：
  //! 若 size 为偶数，则 2 个堆数量相等；
  //! 若 size 为奇数，则 maxHeap.size() = minHeap.size() + 1。
  //! 
  void maintain() {
    while (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    while (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
  }

private:
  std::priority_queue<int> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  
  size_t _size{0};
};


int main() {

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
