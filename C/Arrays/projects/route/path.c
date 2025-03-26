#include "path.h"
#include <cstdlib>
#include <stdio.h>
int main(void) {
  char map[10][10];
  populate_array(map);
  int row = 0, column = 0;
  int token = rand() % 4;
  if ((is_path_valid(row, column))) {
  };
  print_array(map);
  return 0;
}
void populate_array(char map[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      map[i][j] = '.';
    }
  }
}
bool is_path_valid(int row, int column) {
  if (row >= 0 && row < 10 && column >= 0 && column < 10) {
    return true;
  } else
    return false;
}
void print_array(char map[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}
