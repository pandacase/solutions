#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    if (n <= 2) {
      printf("%d\n", n);
      continue;
    }
    
    int res = 2;
    int cnt = 2;
    while (res < n) {
      res = 2 * res - 1;
      cnt += 1;
    }
    printf("%d\n", cnt);
  }
}
// 64 位输出请用 printf("%lld")