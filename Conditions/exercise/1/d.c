#include <stdio.h>
int main(void) {
  int i = 3, j = 4, k = 5;
  printf("%d", i % j + i < k);
  return 0;
}
/************************************************
 * returns 0 here's why .
 * i%j => 3 % 4 which gives 3 as a remainder , as c has tendency to
 * shift towards 0. now 3 + i=> 3 + 3 = 6.
 * now 6 < k => 6 < 5 ? which is ofcourse false
 * so it finally returns 0
 * **********************************************/
