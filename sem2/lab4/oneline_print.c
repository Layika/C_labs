#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5
#define MIN 0
#define MAX 10

double d_rand(double min, double max) {
    return ((double)rand()/RAND_MAX) * (max - min) + min;
}

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

void fill_arr_d(double* arr, int size) {
  for (int i = 0; i < size; ++i)
    arr[i] = d_rand(MIN, MAX);
}

void fill_arr_i(int* arr, int size) {
  for (int i = 0; i < size; ++i)
    arr[i] = i_rand(MIN, MAX);
}

void print_arr_d(double* start, double* end) {
   while (start < end) {
    printf("%6.2f ", *start);
    start++;
  }
  printf("\n");
}

void print_arr_i(int* start, int* end) {
   while (start < end) {
    printf("%4d ", *start);
    start++;
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  double* arr_d = malloc(SIZE * sizeof(double));
  fill_arr_d(arr_d, SIZE);
  print_arr_d(arr_d, arr_d+SIZE);

  int* arr_i = malloc(SIZE * sizeof(int));
  fill_arr_i(arr_i, SIZE);
  print_arr_i(arr_i, arr_i+SIZE);

  free(arr_d);
  free(arr_i);

  return 0;
}
