#include <stdio.h>
int main(void) {
  int numerator, denominator, gcd, greater_no;
  printf("Enter a fraction (a/b) :\n");
  scanf("%d/%d", &numerator, &denominator);
  greater_no = numerator > denominator ? numerator : denominator;
  for (int i = 1; i < greater_no; i++) {
    if (numerator % i == 0 && denominator % i == 0) {
      gcd = i;
    }
  }
  numerator = numerator / gcd;
  denominator = denominator / gcd;
  printf("In lowest terms: %d/%d \n", numerator, denominator);
  return 0;
}
