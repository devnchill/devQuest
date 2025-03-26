#include <stdio.h>
int main(void) {
  int amount;
  printf("Enter the amount : ");
  scanf("%d", &amount);
  int _20_rupee = amount / 20;
  int _remainig_amount = amount - _20_rupee * 20;
  int _10_rupee = _remainig_amount / 10;
  _remainig_amount = _remainig_amount - _10_rupee * 10;
  int _5_rupee = _remainig_amount / 5;
  _remainig_amount = _remainig_amount - _5_rupee * 5;
  int _1_rupee = _remainig_amount / 1;
  _remainig_amount = _remainig_amount - _1_rupee * 1;
  printf("20 rupee: %d\n", _20_rupee);
  printf("10 rupee: %d\n", _10_rupee);
  printf("5 rupee: %d\n", _5_rupee);
  printf("1 rupee: %d\n", _1_rupee);
  return 0;
}
