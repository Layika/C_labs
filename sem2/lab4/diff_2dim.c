#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 4

void print_arr(int* start, int* end) {
   while (start < end) {
    printf("%2d ", *start);
    start++;
  }
  printf("\n");
}

int main() {

  int** arr_1 = calloc(ROWS, sizeof(int*));
  for (int i = 0; i < ROWS; ++i)
    arr_1[i] = calloc(COLS, sizeof(int));
  puts("Printing arr_1:");
  for (int i = 0; i < ROWS; ++i) {
    print_arr(*(arr_1+i), *(arr_1+i)+COLS);
  }
  for (int i = 0; i < ROWS; ++i)
    free(arr_1[i]);
  free(arr_1);
  arr_1 = NULL;


  int** arr_2 = calloc(ROWS, sizeof(int*));
  int* tmp = calloc(COLS*ROWS, sizeof(int)); 
  for (int i = 0; i < ROWS; ++i)
    arr_2[i] = tmp+(i*COLS);
  puts("Printing arr_2:");
  for (int i = 0; i < ROWS; ++i) {
    print_arr(*(arr_2+i), *(arr_2+i)+COLS);
  }
  free(tmp);
  free(arr_2);
  tmp = NULL;
  arr_2 = NULL;


  int (* arr_3)[COLS];
  arr_3 = calloc(ROWS*COLS, sizeof(int));
  puts("Printing arr_3:");
  for (int i = 0; i < ROWS; ++i) {
    print_arr(*(arr_3+i), *(arr_3+i)+COLS);
  }
  free(arr_3);
  arr_3 = NULL;


  int* arr_4 = calloc(ROWS*COLS, sizeof(int));
  puts("Printing arr_4:");
  print_arr(arr_4, arr_4 + (ROWS*COLS));
  free(arr_4);
  arr_4 = NULL;


  return 0;
}
