#include <stdio.h>
#define TRUE 0
#define FALSE 1
int flag = FALSE;
int main(void) {
  if (flag) {
    printf("1st case is executed\n");
    printf("%d is value of flag", flag);
  } else {
    printf("%d is value of flag", flag);
  }
  // if (1 == 1) {
  //   printf("%d is true", TRUE);
  // } else {
  //   printf("%d is false", FALSE);
  // }
  // return 0;
}
