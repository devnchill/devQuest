#include <stdio.h>
int main(void) {
  int i = 5, j = 10, k = 1;
  printf("%d", k > i < j);
  return 0;
}
/*******************************************************************************************************************
 *Compiling using switches gives warning however if i compile it without any of
 *those warning switches , it returns 1
 Here's why
 k>i means 1>5? which is false and false = 0
 so the statement now becomes 0<j which means 0 < 10 ? which is true and true
 means 1 hence printing k shows 1
 *******************************************************************************************************************/
