#include <stdio.h>
int main(void) {
  printf("Enter ISBN: \n");
  int _gsi_prefix, _group_identifier, _publisher_code, _item_no, _check_digit;
  scanf("%d-%d-%d-%d-%d", &_gsi_prefix, &_group_identifier, &_publisher_code,
        &_item_no, &_check_digit);
  printf("GSI prefix: %d\n", _gsi_prefix);
  printf("Groupidentifier: %d\n", _group_identifier);
  printf("Publisher code: %d\n", _publisher_code);
  printf("Item number: %d\n", _item_no);
  printf("Check digit: %d\n", _check_digit);
  return 0;
}
