#include <stdio.h>
int main(void) {
  int i = 3, j = 2, k = 1;
  printf("%d", i < j == j < k);
  return 0;
}
/******************************************************
 * It returns 1 here's why .
 * i<j means 3<2 ? which is falses so 0
 * now 0 == j which means 0 == 2 ? which is again false so 0
 * finally 0 < k => 0 < 1 ? which is true so 1
 * *****************************************************/
