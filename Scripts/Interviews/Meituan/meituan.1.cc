#include <iostream>
#include <vector>
#include <cstdio>

int main() {
  int n;
  std::cin >> n;
  if (n == 0) return 0;

  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int ansOdd = 0, ansEven = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] % 2 != 0) {
      ansOdd += arr[i] + 1;
    } else {
      ansEven += arr[i] + 1;
    }
  }

  std::cout << std::min(ansOdd, ansEven) << std::endl;
  return 0;
}