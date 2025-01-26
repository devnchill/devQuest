#include <stdio.h>
int main(void) {
  typedef int Bool;
  Bool a;
  printf("%ld", sizeof(a));
  return 0;
}
