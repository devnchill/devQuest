#include <stdio.h>
int main(void) {
  float max_num = 0;
  float n = 1;
  do {
    printf("Enter a number: \n");
    scanf("%f", &n);
    if (n > max_num) {
      printf("%f is greater than %f so entered inside the if block", n,
             max_num);
      max_num = n;
    }
  } while (n > 0);
  printf("The largest number entered was %f", max_num);
  return 0;
}
