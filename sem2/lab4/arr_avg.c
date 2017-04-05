#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 4
#define MIN -10
#define MAX 10

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

void fill_arr(int arr[ROWS][COLS], int min, int max) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j)
      arr[i][j] = i_rand(min, max);
  }
}

void print_arr_i(int* start, int* end) {
   while (start < end) {
    printf("%4d ", *start);
    start++;
  }
  printf("\n");
}

void print_arr_d(double* start, double* end) {
   while (start < end) {
    printf("%6.2f ", *start);
    start++;
  }
  printf("\n");
}

double avg(int* arr, int size) {
  double sum = 0;
  for (int i = 0; i < size; ++i)
    sum += arr[i];
  return (double)sum/size;
}

int main() {
  srand(time(NULL));

  int arr[ROWS][COLS];

  fill_arr(arr, MIN, MAX);

  for (int i = 0; i < ROWS; ++i) {
    print_arr_i(*(arr+i), *(arr+i)+COLS);
  }

  int test[6] = {1, 5, 7, -8, -11};
  printf("Average of test: %lf\n", avg(test, 5));

  double avg_rows[ROWS];
  for (int i = 0; i < ROWS; ++i) {
    avg_rows[i] = avg(arr[i], COLS);
  }
  puts("Avgerages:");
  print_arr_d(avg_rows, avg_rows+ROWS);

  puts("Average of all:");
  printf("%lf\n", avg(*arr, ROWS*COLS));

  return 0;
}
