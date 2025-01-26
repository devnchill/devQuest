#include <stdio.h>
int main(void) {
  int radius;
  printf("Enter the value of radius : \n");
  scanf("%d", &radius);
  float volume = 4.0f * (3.14 * radius * radius * radius) / 3.0f;
  printf("%f", volume);
  return 0;
}
