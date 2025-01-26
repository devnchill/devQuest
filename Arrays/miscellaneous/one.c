#include <stdio.h>
int main(void) {
  printf("Enter 10 numbers: ");
  int i = 0;
  int arr[10];
  while (i < 10) {
    scanf("%d", &arr[i]);
    i++;
  }
  printf("In reverse Order: ");
  for (i = 9; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
