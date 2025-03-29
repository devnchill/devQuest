#include <stdio.h>

int marks_summation(int *marks, int number_of_students, char gender) {
  int sum = 0;

  for (int i = 0; i < number_of_students; i++) {
    if (gender == 'g' && i % 2 == 1) {
      sum += marks[i];
    } else if (gender == 'b' && i % 2 == 0) {
      sum += marks[i];
    }
  }

  return sum;
}

int main() {
  int marks[] = {2, 3, 4};
  int number_of_students = 3;

  int boy_sum = marks_summation(marks, number_of_students, 'b');
  int girl_sum = marks_summation(marks, number_of_students, 'g');

  printf("Boys' sum: %d\n", boy_sum);
  printf("Girls' sum: %d\n", girl_sum);

  return 0;
}
