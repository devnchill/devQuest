#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int remove_duplicates(int *nums, int num_size) {
  int *arr = malloc((sizeof(int) * num_size));
  if (arr == NULL) {
    return -1;
  }
  int j = 1;
  arr[0] = nums[0];
  for (int i = 1; i < num_size; i++) {
    if (nums[i] != nums[i - 1]) {
      arr[j] = nums[i];
      j++;
    }
  }
  for (int i = 0; i < j; i++) {
    nums[i] = arr[i];
  }
  free(arr);
  return j;
}

int main(void) {
  int ptr[4] = {2, 2, 3, 5};
  int ptr_size = sizeof(ptr) / sizeof(ptr[0]);
  ptr_size = remove_duplicates(ptr, ptr_size);
  for (int i = 0; i < ptr_size; i++) {
    printf("%d\n", ptr[i]);
  }
  return 0;
}
