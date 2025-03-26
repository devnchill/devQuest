#include <stdio.h>
int main(void) {
  int _item_number, month, day, year;
  float _unit_price;
  printf("Enter item number: \n");
  scanf("%d", &_item_number);
  printf("Enter unit price: \n");
  scanf("%f", &_unit_price);
  printf("Enter purchase date (mm/dd/yyyy): \n");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("Item\tUnit Price\tPurchase Date\n");
  printf("%-4d\t%-12.2f\t%02d%02d%d", _item_number, _unit_price, month, day, year);
  return 0;
}
