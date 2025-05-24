#include <math.h>
#include <stdio.h>

int *log_scale(int *data, int len, int base) {
  for (int i = 0; i < len; i++) {
    int log_val = (int)round(log(data[i]) / log(base));
    data[i] = log_val;
  }
  return data;
}

int main(void) {
  int data[] = {10, 100, 1000};
  int length = sizeof(data) / sizeof(data[0]);
  log_scale(data, length, 10);
  for (int i = 0; i < length; i++) {
    printf("%d\n", data[i]);
  }
  return 0;
}
