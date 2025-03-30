#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

typedef struct box {
  int length;
  int width;
  int height
} box;

int get_volume(box b) {
  /**
   * Return the volume of the box
   */
  return b.length * b.width * b.height;
}

int is_lower_than_max_height(box b) {
  /**
   * Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
   */
  if (b.height < 41) {
    return 1;
  }
  return 0;
}

int main() {
  box b;
  if (is_lower_than_max_height(b) == 1) {
    return get_volume(b);
  }
}
