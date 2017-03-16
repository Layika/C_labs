#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>

#define SIZE 4
#define ARRS_COUNT 5
#define MIN_PRODUCT 0.0

double d_rand(double min, double max) {
  return ((double)rand()/RAND_MAX) * (max - min) + min;
}

void fill_arr(double* array, int size, int min, int max) {
  for (int i = 0; i < size; ++i)
    array[i] = d_rand(min, max);
}

void print_2d(double** arr, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
   for (int j = 0; j < cols; ++j)
	    printf("%.2lf  ", arr[i][j]);
   printf ("\n");
  }
}

double product(double** arr, int arr_num, int size) {
  double product = 1.0;
  for (int i = 0; i < size; ++i)
    product *= arr[arr_num-1][i];
  return product;
}

int find_max_product_arr(double** arr, int arr_count, int arr_size) {
  double max_product = MIN_PRODUCT;
  int idx = 0;
  for (int i = 1; i <= arr_count; ++i) {
    double tmp = product(arr, i, arr_size);
    if (tmp > max_product) {
      max_product = tmp;
      idx = i;
    }
  }
  return idx;
}

void swap(double** arr, int first, int second) {
    double* tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

void sort_2d(double** arr, int arr_count, int arr_size) {
  for (int i = arr_count-1; i >= 0; --i) {

    int idx = find_max_product_arr(arr, i+1, arr_size);

    if (idx == arr_count)
      continue;
    swap(arr, i, idx-1);
  }
}

int main() {
  srand(time(NULL));
  double arr_1[SIZE];
  double arr_2[SIZE];
  double arr_3[SIZE];
  double arr_4[SIZE];
  double arr_5[SIZE];
  fill_arr(arr_1, SIZE, 0, 10);
  fill_arr(arr_2, SIZE, 0, 10);
  fill_arr(arr_3, SIZE, 0, 10);
  fill_arr(arr_4, SIZE, 0, 10);
  fill_arr(arr_5, SIZE, 0, 10);
  double* arr[ARRS_COUNT] = {arr_1, arr_2, arr_3, arr_4, arr_5};

  print_2d(arr, sizeof(arr)/sizeof(double*), SIZE);

  printf("product of %d array: %.2lf\n", 1, product(arr, 1, SIZE));
  printf("product of %d array: %.2lf\n", 2, product(arr, 2, SIZE));
  printf("product of %d array: %.2lf\n", 3, product(arr, 3, SIZE));
  printf("product of %d array: %.2lf\n", 4, product(arr, 4, SIZE));
  printf("product of %d array: %.2lf\n", 5, product(arr, 5, SIZE));
  printf("\n");

  printf("Biggest product in array %d\n", find_max_product_arr(arr, ARRS_COUNT, SIZE));
  printf("\n");

  puts("After sorting:");
  sort_2d(arr, ARRS_COUNT, SIZE);
  print_2d(arr, sizeof(arr)/sizeof(double*), SIZE);

  puts("Testing swap:");
  double a[1];
  double b[1];
  double* c[2] = {a, b};

  printf("addr in c: %p, addr in c+1: %p\n", (void*)*c, (void*)c[1]);
  swap(c, 0, 1);
  printf("addr in c: %p, addr in c+1: %p\n", (void*)*c, (void*)c[1]);
  return 0;
}
