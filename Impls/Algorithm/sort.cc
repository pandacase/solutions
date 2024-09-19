#include <iostream>
#include <vector>

class Sort {
public:
  void insertionSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
      int key = vec[i];
      int j = i - 1;
      while (j >= 0 && vec[j] > key) {
        vec[j + 1] = vec[j];
        j -= 1;
      }
      vec[j + 1] = key;
    }
  }

  void quickSort(std::vector<int>& vec) {
    quickSort(vec, 0, vec.size() - 1);
  }

  void mergeSort(std::vector<int>& vec) {
    mergeSort(vec, 0, vec.size() - 1);
  }

private:
  // Quick Sort ///////////////////////////////////////////////////
  void quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
      int pivotIdx = partitionForQS(vec, low, high);
      quickSort(vec, low, pivotIdx - 1);
      quickSort(vec, pivotIdx + 1, high);
    }
  }
  //! @return int : the pivot index
  int partitionForQS(std::vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low;

    for (int j = low; j < high; ++j)
      if (vec[j] < pivot)
        std::swap(vec[i++], vec[j]);

    std::swap(vec[i], vec[high]);
    return i;
  }
  /////////////////////////////////////////////////////////////////
  void mergeSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
      int mid = low + (high - low) / 2;
      mergeSort(vec, low, mid);
      mergeSort(vec, mid + 1, high);
      merge(vec, low, mid, high);
    }
  }

  void merge(std::vector<int>& vec, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    std::vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; ++i)
      left[i] = vec[low + i];
    for (int i = 0; i < n2; ++i) 
      right[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 || j < n2) {
      int val1 = i < n1 ? left[i] : INT32_MAX;
      int val2 = j < n2 ? right[j] : INT32_MAX;

      if (val1 < val2) {
        vec[k++] = val1;
        i += 1;
      } else {
        vec[k++] = val2;
        j += 1;
      }
    }
  }
};

int main() {
  Sort sol;
  std::vector<int> arr = {10, 7, 8, 9, 1, 5, 4, 11, 3};
  sol.mergeSort(arr);
  for (int x : arr)
    std::cout << x << " ";
  std::cout << std::endl;
}
