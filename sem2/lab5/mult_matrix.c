#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define print_arr(arr, rows, cols) print(&arr[0][0], rows, cols)

void print(int* arr, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      printf("%2d |", *(arr + i*cols + j));
    printf("\n");
  }
  printf("\n");
}

void mult_matrix(int r1, int c1, int c2, int arr_a[][c1], int arr_b[][c2], int arr_c[][c2]) {
  for (int i = 0; i < r1; ++i) {
    for (int j = 0; j < c2; ++j) {
      for (int k = 0; k < c1; ++k)
        arr_c[i][j] += arr_a[i][k] * arr_b[k][j];
    }
  }
}

int main() {
  int arr_a[2][3] = { {1, 2, 3}, {4, 5, 6} };
  int arr_b[3][4] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };
  int arr_c[2][4] = { 0 };

  puts("arr_a:");
  print_arr(arr_a, 2, 3);
  puts("arr_b:");
  print_arr(arr_b, 3, 4);

  puts("Multiplying:");
  mult_matrix(2, 3, 4, arr_a, arr_b, arr_c);
  print_arr(arr_c, 2, 4);
  return 0;
}
