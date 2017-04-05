#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

double d_rand(double min, double max) {
  return ((double)rand()/RAND_MAX) * (max - min) + min;
}

void fill_arr(double** arr, int rows, int cols, int min, int max) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      arr[i][j] = d_rand(min, max);
  }
}

void print_arr(double** arr, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      printf(" %lf |", arr[i][j]);
    printf("\n");
  }
}

double sum_diagonal(double** arr, int rows, int cols) {
  double sum = 0.0;
  if (rows == cols) {                                  // check if diagonal exists
    for (int i = 0; i < rows; ++i)
      sum += arr[i][i];
  }
  return sum;
}

double sum_under(double** arr, int rows, int cols) {
  double sum = 0.0;
  if (rows == cols) {
    for (int i = 0; i < rows-1; ++i)
      sum += arr[i+1][i];
  }
  return sum;
}

double sum_col(double** arr, int col, int rows) {
  double sum = 0.0;
  for (int i = 0; i < rows; ++ i)
    sum += arr[i][col];
  return sum;
}

void swap(double* first, double* second) {
  double tmp = *first;
  *first = *second;
  *second = tmp;
}

void transpose_1(double** arr, int rows, int cols) {
  for (int j = 0; j < cols/2; ++j) {
    for (int i = 0; i < rows/2; ++i)
      swap(&(arr[i][j]), &(arr[j][i]));
  }
}

void transpose(double** arr, int cols) {
  for (int j = 0; j < cols; ++j) {
    for (int i = 0; i < j; ++i)
      swap(&(arr[i][j]), &(arr[j][i]));
  }
}

int main() {
  srand(time(NULL));

  double** arr = malloc(ROWS*sizeof(double*));
  for(int i = 0; i < ROWS; ++i)
    arr[i] = malloc(COLS*sizeof(double));

  fill_arr(arr, ROWS, COLS, 10.0, 20.0);
  print_arr(arr, ROWS, COLS);

  printf("Sum on diagonal: %lf\n", sum_diagonal(arr, ROWS, COLS));
  printf("Sum under diagonal: %lf\n", sum_under(arr, ROWS, COLS));
  for (int i = 0; i < COLS; ++i)
    printf("Sum of %d col: %lf\n", i, sum_col(arr, i, ROWS));

  puts("After transposing:");
  transpose(arr, COLS);
  print_arr(arr, ROWS, COLS);

  for (int i = i; i < ROWS; ++i)
    free(arr[i]);
  free(arr);
  arr = NULL;
  return 0;
}
