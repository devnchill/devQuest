#include <stdio.h>
int main(void) {
  int fib_array[40];
  int j = 0;
  for (int i = 0; i < 40; i++) {
    if (i <= 1) {
      fib_array[i] = i;
    }
    fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
  }
  while (j < 40) {
    printf("%d\n", fib_array[j]);
    j++;
  }
}
