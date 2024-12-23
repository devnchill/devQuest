#include <stdio.h>
int main(void) {
  int length = 8;
  int breadth = 10;
  int height = 8;
  int volume = length * breadth * height;
  printf("Dimensional wieght : %d\n", (volume + 165) / 166);
  return 0;
}
