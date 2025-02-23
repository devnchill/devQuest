#include <stdio.h>
int main(void) {
  int i = 10, j = 5;
  printf("%d", !i < j);
  return 0;
}
/******************************************************************************
*! means not , so basically not (i<j) => not(10<5) => not(false) => true hence
returns 1
******************************************************************************/
