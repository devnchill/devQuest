#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4
#define MIN 1

int ascii_val = 65;
int validate_coord(int a, int b, char arr[][10]) {
  return a >= 0 && a < 10 && b >= 0 && b < 10 && arr[a][b] == '.' &&
         ascii_val < 91;
}

int main(void) {
  srand(time(NULL));
  char arr[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      arr[i][j] = '.';
    }
  }
  int row = 0;
  int col = 0;
  arr[row][col] = (char)ascii_val;
  while (1) {
    int rand_no = (rand() % (MAX - MIN + 1)) + MIN;

    /***************************************
     * 1 -> travel 1 step north
     * 2 -> travel 1 step east
     * 3 -> travel 1 step south
     * 4 -> travel 1 step west
     *************************************/

    int new_row = row;
    int new_col = col;
    switch (rand_no) {
    case 1:
      new_row = row - 1;
      break; // north
    case 2:
      new_col = col + 1;
      break; // east
    case 3:
      new_row = row + 1;
      break; // south
    case 4:
      new_col = col - 1;
      break; // west
    }

    // Validate before move
    if (validate_coord(new_row, new_col, arr)) {
      ascii_val++;
      arr[new_row][new_col] = (char)ascii_val;
      row = new_row;
      col = new_col;
    } else {
      break;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
