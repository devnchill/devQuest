#include <stdio.h>
int main(void) {
  int total_days, starting_day;
  printf("Enter number of days in month: \n");
  scanf("%d", &total_days);
  printf("Enter starting  day of the week(1=Sun, 7=Sat): \n");
  scanf("%d", &starting_day);
  for (int j = 0; j < starting_day; j++) {
    printf("  ");
  }
  for (int i = 1; i <= total_days; i++) {
    printf("%d ", i);
    if ((starting_day + i) % 7 == 0) {
      printf("\n");
    }
  }
  return 0;
}
