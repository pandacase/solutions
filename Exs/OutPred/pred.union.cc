
#include <stdio.h>

union {
  int i;
  char x[2];
} a;

int
main()
{
  a.i = 0;
  a.x[0] = 10;
  a.x[1] = 1;
  printf("%d", a.i);

  // 0000_0010 0000_0001
  // 0000_0001 0000_0010
}
