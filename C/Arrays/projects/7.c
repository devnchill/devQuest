#include <stdio.h>
#define ROWS 5
#define COLUMNS 5
int main(void) {
  int array_of_integers[5][5] = {0}, row_total = 0, column_total = 0;
  for (int i = 0; i < ROWS; i++) {
    printf("Enter row %d: ", i + 1);
    scanf("%d %d %d %d %d", &array_of_integers[i][0], &array_of_integers[i][1],
          &array_of_integers[i][2], &array_of_integers[i][3],
          &array_of_integers[i][4]);
  }
  printf("Row totals: ");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      row_total += array_of_integers[i][j];
      column_total += array_of_integers[j][i];
    }
    printf("%d ", row_total);
    row_total = 0;
    printf("%d ", column_total);
    column_total = 0;
  }
  return 0;
}
