#include <stdio.h>
int main(void) {
  int rupee, paise;
  printf("Enter amount in rupee and paise: \n");
  scanf("%d %d", &rupee, &paise);
  int _total_amount = rupee + paise / 100;
  int tax = (_total_amount) / 20;
  int _final_amount = tax + _total_amount;
  printf("With tax added: %d", _final_amount);
  return 0;
}
