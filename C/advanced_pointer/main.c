#include <stdio.h>
#include <stdlib.h>
void allocate_int(int **pointer_pointer, int value);
int main(void) { return 0; }
void allocate_int(int **pointer_pointer, int value) {
  int *pointer = malloc(sizeof(int));
  *pointer = value;
  *pointer_pointer = pointer;
};
