#include <stdio.h>
int removeElement(int *nums, int numsSize, int val) {
  int j = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[j] = nums[i];
      j++;
    }
  }
  return j;
}

int main(void) {
  int nums[] = {3, 2, 2, 3, 4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int val = 3;

  int k = removeElement(nums, numsSize, val);
  printf("Number of elements not equal to %d: %d\n", val, k);
  for (int i = 0; i < k; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}
