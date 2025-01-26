#include <stdio.h>
int main(void) {
  int num;
  printf("Enter a nuber: \n");
  scanf("%d", &num);
  if (-10 < num && num < 10) {
    printf("The number %d has 1 digit", num);
  } else if ((-100 < num && num < -10) || (10 <= num && num < 100)) {
    printf("The number %d has 2 digit", num);
  } else if ((-1000 < num && num <= -100) || (100 <= num && num < 1000)) {
    printf("The number %d has 3 digit", num);
  } else if ((-10000 < num && num <= -1000) || (1000 <= num && num < 10000)) {
    printf("The number %d has 3 digit", num);
  }
  return 0;
}
