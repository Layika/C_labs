#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 20
#define MIN 0
#define MAX 30 // MAX should to be bigger than SIZE

double d_rand(double min, double max);
void fill_array(float* array, int size);
void print_arr(float* arr, int size);
float sum(float* arr, int size, float* min, float* max, float* avg, float* max_diff, float* min_diff);

int main() {
  srand(time(NULL));
  float arr[SIZE];
  fill_array(arr, SIZE);

  float min = 0;
  float max = 0;
  float avg = 0;
  float min_diff;
  float max_diff;

  float res = sum(arr, SIZE, &min, &max, &avg, &max_diff, &min_diff);

  puts("Array:");
  print_arr(arr, SIZE);
  printf("Sum = %f\nMin = %f\nMax = %f\nAvg = %f\nMax_diff = %f\nMin_diff = %f\n", res, min, max, avg, max_diff, min_diff);

  return 0;
}

double d_rand(double min, double max) {
    double random = ((double)rand()/RAND_MAX) * (max - min) + min;
    return random;
}

void fill_array(float* array, int size) {
  for (float* val = array; val < array+size; ++val)
    *val = d_rand(0, 100);
}

void print_arr(float* arr, int size) {
  for (int i = 0; i < size; ++i)
    printf("%f ", arr[i]);
  printf("\n");
}

float sum(float* arr, int size, float* min, float* max, float* avg, float* max_diff, float* min_diff) {
  float sum = 0;
  *min = arr[0];
  *max = arr[0];

  for (int i = 0; i < size; ++i) { // count sum, find min and max
    if (arr[i] < *min)
      *min = arr[i];
    if (arr[i] > *max)
      *max = arr[i];
    sum += arr[i];
  }

  *avg = sum / size;

  *max_diff = MIN;
  *min_diff = MAX;
  float tmp_max;
  float tmp_min;
  for (int i = 0; i < size; ++i) {
    tmp_max = fabs(*avg - arr[i]);
    tmp_min = fabs(*avg - arr[i]);

    if (tmp_max > *max_diff)
      *max_diff = tmp_max;
    if (tmp_min < *min_diff)
      *min_diff = tmp_min;
  }

  return sum;
}
