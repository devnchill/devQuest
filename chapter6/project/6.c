#include <stdio.h>
int main(void) {
  int n;
  printf("Enter a number :\n");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      printf("%d\n", i * i);
    }
  }
  return 0;
}
