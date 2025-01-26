#include <stdio.h>
int main(void) {
  const int segments[10][7] = {
      {1, 1, 1, 1, 1, 0, 1}, // will display 0
      {0, 1, 1, 0, 0, 0, 0}, // will display 1
      {1, 1, 0, 1, 1, 0, 1}, // will display 2
      {1, 1, 1, 1, 0, 0, 1}, // will display 3
      {0, 1, 1, 0, 0, 1, 1}, // will display 4
      {1, 0, 1, 0, 1, 1, 1}, // will display 5
      {1, 0, 1, 1, 1, 1, 1}, // will display 6
      {1, 1, 1, 0, 0, 0, 0}, // will display 7
      {1, 1, 1, 1, 1, 1, 1}, // will display 8
      {1, 1, 1, 1, 0, 1, 1}, // will display 9
  };
  return 0;
}
