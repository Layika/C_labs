#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 4

void print_arr(int arr[][COLS], int rows) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < COLS; ++j)
      printf("%2d |", arr[i][j]);
    printf("\n");
  }
}

int** mult_matrix(int r1, int c1, int c2, int arr_a[][c1], int arr_b[][c2]) {
  int** arr_c = malloc(sizeof(int*) * r1);
  for (int i = 0; i < COLS; ++i)
    arr_c[i] = malloc(sizeof(int) * COLS);

  for (int i = 0; i < r1; ++i) {
    for (int j = 0; j < c2; ++j) {
      for (int k = 0; k < c1; ++k)
        arr_c[i][j] += arr_a[i][k] * arr_b[k][j];
    }
  }
    return arr_c;
}

int main() {
  int arr_a[2][3] = { {1, 2, 3}, {4, 5, 6} };
  int arr_b[3][4] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };

  puts("Multiplying:");
  int** arr_c =  mult_matrix(2, 3, 4, arr_a, arr_b);
  if (!arr_c) {
    puts("Allocation failed!");
    exit(-1);
  }

  for (int i = 0; i < ROWS; ++i)
    print_arr((int (*)[COLS])arr_c[i], 1);

  free(arr_c);

  return 0;
}
