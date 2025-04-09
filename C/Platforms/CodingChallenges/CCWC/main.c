#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc < 3 || !strcmp(argv[0], "ccwc")) {
    printf("Usage: ccwc <command>\n");
    return 1;
  }
  return 0;
}
