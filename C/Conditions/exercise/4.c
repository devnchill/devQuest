#include <stdio.h>
int main(void) {
  int i, j;
  printf("Enter the value of a and b : ");
  scanf("%d %d", &i, &j);
  if (i > j) {
    return -1;
  } else if (i == j) {
    return 0;
  } else {
    return 1;
  }
  return 0;
}
