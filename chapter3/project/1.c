#include <stdio.h>
int main(void) {
  int day, month, year;
  printf("Enter date in [mm/dd/yyyy] format : \n");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("You entered the date : %d%02d%02d", year, month, day);
  return 0;
}
