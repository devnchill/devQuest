#include <stdio.h>
int main(void) {
  int sum = 0, sum_avg_temp_day = 0;
  float avg_temp_day = 0.0f, avg_temp_month = 0.0f;
  const int temperature_readings[30][24];
  for (int i = 0; i < 30; i++) {
    sum = 0;
    for (int j = 0; j < 24; j++) {
      sum += temperature_readings[i][j];
    }
    avg_temp_day = sum / 24.00f;
    sum_avg_temp_day += avg_temp_day;
  }
  avg_temp_month = sum_avg_temp_day / 30.00f;
  return 0;
}
