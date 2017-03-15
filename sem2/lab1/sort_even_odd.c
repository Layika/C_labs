#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 21

int rand_int(int min, int max);
void swap(int* first, int* second);
void print_arr(int* arr, int size);
void reorder(int* arr);
bool test_reordered(int* arr);

int main() {
  srand(time(NULL));
  int arr[SIZE];
  for (int i = 0; i < SIZE; ++i)
    arr[i] = rand_int(0, 40);

  puts("BEFORE:");
  print_arr(arr, SIZE);

  puts("AFTER:");
  reorder(arr);
  print_arr(arr, SIZE);

  if(test_reordered(arr))
    puts("Reordering succeeded!");

  return 0;
}


int rand_int(int min, int max){
    return rand() % (max-min+1) + min;
}

void swap(int* first, int* second) {
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

void print_arr(int* arr, int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void reorder(int* arr) {
  int changed = SIZE - 1;

  for (int i = 0; i < changed; ++i) {
    if (arr[i]%2) {
      //printf("Need to swap: %d, searching for value...\n", arr[i]);
      for (int j = changed; j > i; --j) {
        if (arr[j]%2 == 0) {
          //printf("Found value: %d, swapping!\n", arr[j]);
          swap(arr+i, arr+j);
          changed = j;                 // changed is now an index of the last odd value
          break;
        }
      }
    }
    if (changed == i + 1)              // i is an index of the last even value
      break;
  }
}

bool test_reordered(int* arr) {
  int begin = 0;
  int end = SIZE - 1;

  for (int i = 0; i < SIZE; ++i) {     // finds the last even value (beginning)
    if (arr[i] % 2) {
      begin = i - 1;
      break;
    }
  }

  for (int i = end; i >= 0; --i) {     // finds the first even value (end)
    if (arr[i] % 2 == 0){
      end = i;
      break;
    }
  }

  if (begin == end)                    // equal indexes mean that the last even value counting from the beginning is the first one counting from the end
    return true;
  return false;
}
