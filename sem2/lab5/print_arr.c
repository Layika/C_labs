#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 4
#define MIN 0
#define MAX 10

#define print(arr, rows, cols) print_by_rows(&arr[0][0], rows, cols)

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

void fill_arr(int* start, int* end, int min, int max) {
  while (start < end) {
    *start = i_rand(min, max);
    start++;
  }
}

void print_arr(int* start, int* end) {
   while (start < end) {
    printf("%3d ", *start);
    start++;
  }
  printf("\n");
}

/* printing functions: */

void print_by_rows(int arr[][COLS], int rows) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < COLS; ++j)
      printf("%3d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

void print_oneline(int *arrptr, int size) {
  for (int i = 0; i < size; ++i)
    printf("%3d ", arrptr[i]);
  printf("\n");
}

void print_by_rows_ptr(int** arr, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      printf("%3d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  /* arr1 */
  int** arr1 = calloc(ROWS, sizeof(int*));
  if (arr1 == NULL) {
    exit(-1);
  }
  for (int i = 0; i < ROWS; ++i) {
    arr1[i] = calloc(COLS, sizeof(int));
    if (arr1[i] == NULL)
      exit(-1);
  }
  puts("Printing arr1:");
  for (int i = 0; i < ROWS; ++i) {
    fill_arr(arr1[i], arr1[i]+COLS, MIN, MAX);
    print_arr(arr1[i], arr1[i]+COLS);
  }
  printf("\n");


  /* arr2 */
  int** arr2 = calloc(ROWS, sizeof(int*));
  if (arr2 == NULL)
    exit(-1);
  arr2[0] = calloc(COLS*ROWS, sizeof(int));
  if (arr2[0] == NULL)
    exit(-1);
  for (int i = 0; i < ROWS; ++i)
    arr2[i] = arr2[0] + i*COLS;
  puts("Printing arr2:");
  for (int i = 0; i < ROWS; ++i) {
    fill_arr(arr2[i], arr2[i]+COLS, MIN, MAX);
    print_arr(arr2[i], arr2[i]+COLS);
  }
  printf("\n");

  /* arr3 */
  int (* arr3)[COLS];
  arr3 = calloc(ROWS*COLS, sizeof(int));
  if (arr3 == NULL)
    exit(-1);
  puts("Printing arr3:");
  for (int i = 0; i < ROWS; ++i) {
    fill_arr(arr3[i], arr3[i]+COLS, MIN, MAX);
    print_arr(arr3[i], arr3[i]+COLS);
  }
  printf("\n");

  /* arr4 */
  int* arr4 = calloc(ROWS*COLS, sizeof(int));
  if (arr4 == NULL)
    exit(-1);
  puts("Printing arr4:");
  fill_arr(arr4, arr4 + ROWS*COLS, MIN, MAX);
  print_arr(arr4, arr4 + ROWS*COLS);
  printf("\n");

  /* arr5 */
  int arr5[ROWS][COLS] = {{0}};
  puts("Printing arr5:");
	for (int i = 0; i < ROWS; ++i) {
	  fill_arr(arr5[i], arr5[i]+COLS, MIN, MAX);
    print_arr(arr5[i], arr5[i]+COLS);
  }
  printf("\n\n");

  puts("-----------------------------------------------------------------------------");
  puts("First printing function: (print by rows)");
  puts("arr3:");
  print_by_rows(arr3, ROWS);
  puts("arr5:");
  print_by_rows(arr5, ROWS);

  printf("\n");
  puts("Second printing function: (print in one line)");
  puts("arr1:");
  for (int i = 0; i < ROWS; ++i)
    print_oneline(arr1[i], COLS);
  printf("\n");
  puts("arr2:");
  for (int i = 0; i < ROWS; ++i)
    print_oneline(arr2[i], COLS);
  printf("\n");
  puts("arr3:");
  print_oneline(*arr3, ROWS*COLS);
  printf("\n");
  puts("arr4:");
  print_oneline(arr4, ROWS*COLS);
  printf("\n");
  puts("arr5:");
  print_oneline(*arr5, ROWS*COLS);

  printf("\n\n");
  puts("Third printing function: (print by rows using pointer)");
  puts("arr1:");
  print_by_rows_ptr(arr1, ROWS, COLS);
  puts("arr2:");
  print_by_rows_ptr(arr2, ROWS, COLS);
  puts("arr3:");
  arr3 = (int (*)[COLS])arr3;
  print_by_rows(arr3, ROWS);
  puts("arr4:");
  print_by_rows_ptr(&arr4, 1, COLS*ROWS);

  /* freeing */
  for (int i = 0; i < ROWS; ++i)
    free(arr1[i]);
  free(arr1);
  arr1 = NULL;

  free(arr2[0]);
  free(arr2);
  arr2[0] = NULL;
  arr2 = NULL;

  free(arr3);
  arr3 = NULL;

  free(arr4);
  arr4 = NULL;
  return 0;
}
