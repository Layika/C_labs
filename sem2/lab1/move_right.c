#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

int rand_int(int min, int max){
    return rand() % (max-min+1) + min;
}

void print_arr(int* arr, int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n\n");
}

void shift_arr(int* arr, int size, int pos) {
  int tmp;
  for (int i = 0; i < pos; ++i) {
    tmp = arr[size-1];
    memmove(arr+1, arr, (size - 1)*sizeof(int));
    arr[0] = tmp;
  }
}

int main() {
  srand(time(NULL));
  int arr[SIZE];
  for (int i = 0; i < SIZE; ++i)
    arr[i] = rand_int(5, 29);
  puts("ARRAY:");
  print_arr(arr, SIZE);

  puts("Shift by one:");
  shift_arr(arr, SIZE, 1);
  print_arr(arr, SIZE);

  puts("Shift by five:");
  shift_arr(arr, SIZE, 5);
  print_arr(arr, SIZE);
  return 0;
}
