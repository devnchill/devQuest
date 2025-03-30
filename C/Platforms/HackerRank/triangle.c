#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct triangle {
  int a;
  int b;
  int c;
} triangle;

void sort_by_area(triangle *tr, int n) {
  /**
   * Sort an array a of the length n
   */
  triangle min = tr[0];
  float p = (min.a + min.b + min.c) / 2.0;
  float area_previous = sqrtf(p * (p - min.a) * (p - min.b) * (p - min.c));
  for (int i = 1; i < n; i++) {
    triangle curr = tr[i];
    float p = (curr.a + curr.b + curr.c) / 2.0;
    float area_curr = sqrtf(p * (p - curr.a) * (p - curr.b) * (p - curr.c));
    if (area_curr < area_previous) {
      triangle temp = tr[i];
      tr[i - 1] = tr[i];
      tr[i] = temp;
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  triangle *tr = malloc(sizeof(triangle) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &tr[i].a, &tr[i].b, &tr[i].c);
  }
  sort_by_area(tr, n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d", tr[i].a, tr[i].b, tr[i].c);
  }
  free(tr);
  return 0;
}
