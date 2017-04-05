#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5
#define MIN 0.0
#define MAX 10.0

double d_rand(double min, double max) {
    return ((double)rand()/RAND_MAX) * (max - min) + min;
}

void fill_arr(double* arr, int size) {
  for (int i = 0; i < size; ++i)
    arr[i] = d_rand(MIN, MAX);
}

void print_arr(double* start, double* end) {
   while (start < end) {
    printf("%3.2lf | ", *start);
    start++;
  }
  printf("\n");
}

double sum(double (*arr)[5], int size) {
  double sum = 0.0;
  for (int  i = 0; i < size; ++i)
    sum += (*arr)[i];
  return sum;
}

int main() {
  srand(time(NULL));

  double* arr = malloc(SIZE * sizeof(double));
  fill_arr(arr, SIZE);
  print_arr(arr, arr+SIZE);

  printf("Sum of array: %lf\n", sum((double (*)[5])arr, SIZE));

  free(arr);
  return 0;
}
