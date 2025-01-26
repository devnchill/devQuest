#include <stdbool.h>
#include <stdio.h>
int main(void) {
  bool weekend[7] = {false};
  weekend[0] = true;
  weekend[6] = true;
  for (unsigned i = 0; i < sizeof(weekend) / sizeof(weekend[0]); i++) {
    weekend[i] == true ? printf("true\n") : printf("false\n");
  }
  return 0;
}
