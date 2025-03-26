#include <stdio.h>

#define LENGTH 10

int main(void) {
  long number;
  int digit;
  int frequency[LENGTH] = {0};

  printf("Enter a number: ");
  scanf("%ld", &number);

  while (number > 0) {
    digit = number % 10;
    frequency[digit]++;
    number /= 10;
  }

  printf("Repeated digits: ");
  int has_repeated = 0;
  for (int i = 0; i < LENGTH; i++) {
    if (frequency[i] > 1) {
      printf("%d ", i);
      has_repeated = 1;
    }
  }

  if (!has_repeated) {
    printf("None");
  }

  printf("\n");
  return 0;
}
