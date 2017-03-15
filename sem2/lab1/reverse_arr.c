#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void reverse_arr(int* arr, int size);
void switch_arr(int*, int, int*, int);
void print_arr(int*, int);

int main() {
  int first = 10;
  int second = 20;
  swap(&first, &second);
  printf("first = %d, second = %d\n", first, second);

  int arr[11];
  int arr_sec[11];

  int size = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < size; ++i)
    arr[i] = i;
  reverse_arr(arr, size);
  print_arr(arr, size);
  printf("\n");

  for (int i = 0; i < size; ++i)
    arr_sec[i] = i + 11;
  printf("BEFORE:\narr: ");
  print_arr(arr, size);
  printf("arr_sec: ");
  print_arr(arr_sec, size);

  switch_arr(arr, size, arr_sec, size);

  printf("AFTER:\narr: ");
  print_arr(arr, size);
  printf("arr_sec: ");
  print_arr(arr_sec, size);

  return 0;
}

void swap(int* first, int* second) {
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

void reverse_arr(int* arr, int size) {
  for (int i = 0; i < size/2; ++i)
    swap(arr + i, &arr[size - 1 - i]);
  printf("\n");
}

void switch_arr(int* arr_first, int size_first, int* arr_second, int size_second) {
  if (size_first != size_second) {
    puts("Expecting arrays of equal length");
    exit(-1);
  }
  for (int i = 0; i < size_first; ++i)
    swap(arr_first + i, arr_second + i);
}

void print_arr(int* arr, int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}
