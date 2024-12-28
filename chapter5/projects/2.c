#include <stdio.h>
int main(void) {
  int hour, minute;
  printf("Enter a 24-hour time: \n");
  scanf("%d:%d", &hour, &minute);
  if (hour <= 12) {
    hour = hour;
  } else if (hour <= 24 && hour > 12) {
    hour = hour - 12;
  } else {
    printf("Invalid hour you idiot");
  }
  printf("Equivalient 12-hour time: %02d:%02d", hour, minute);
  return 0;
}
