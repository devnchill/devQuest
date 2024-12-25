#include <stdio.h>
int main(void) {
  int i = 2, j = 3;
  int k = i * j == 6;
  printf("%d", k);
  return 0;
}
/****************************************************************************
 * k  = 2 * 3 == 6 , so basically says k = 6 == 6 , which is true , and true
 * means 1 so k = 1 so it will print 1
 ***************************************************************************/
