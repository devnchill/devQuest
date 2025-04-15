#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct influencer {
  int num_selfies;
  int num_bio_links;
} influencer;

int vanity(influencer i) { return i.num_selfies + 5 * i.num_bio_links; }
int *bubblesort(int *arr, size_t len) {
  for (size_t j = 0; j < len - 1; j++) {
    for (size_t i = 0; i < len - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
  return arr;
}
influencer *vanity_sort(influencer *influencers, size_t len_influencers) {
  int *arr_of_van = malloc(sizeof(int) * len_influencers);
  for (size_t i = 0; i < len_influencers; i++) {
    int v = vanity(influencers[i]);
    arr_of_van[i] = v;
  }
  int *sorted_arr_of_van = bubblesort(arr_of_van, len_influencers);
  influencer *sorted_influencers = malloc(sizeof(influencer) * len_influencers);
  for (size_t j = 0; j < len_influencers; j++) {
    for (size_t a = 0; a < len_influencers; a++) {
      if (vanity(influencers[j]) == sorted_arr_of_van[a]) {
        sorted_influencers[j] = influencers[a];
      }
    }
  }
  return sorted_influencers;
}

int main(int argc, char *argv[]) {
  int len = 10;
  influencer *a = malloc(len * sizeof(influencer));
  for (int i = 0; i < len; i++) {
    a[i].num_bio_links = i + len;
    a[i].num_selfies = len * len + i;
  }
  influencer *arr = vanity_sort(a, len);
  for (int i = 0; i < len; i++) {
    printf("%d\n", vanity(arr[i]));
  }
  return 0;
  free(a);
  free(arr);
}
