#include <stdio.h>
int main(void) {
  int num1, num2;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);
  int gcd, greater_no;
  gcd = num1 > num2 ? num1 : num2;
  for (int i = 1; i < greater_no; i++) {
    if (num1 % i == 0 && num2 % i == 0) {
      gcd = i;
    }
  }
  printf("Greatest common dvivisor: %d", gcd);
  return 0;
}
