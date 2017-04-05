#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define SIZE_ONE 10
#define SIZE_TWO 15

double d_rand(double min, double max) {
    return ((double)rand()/RAND_MAX) * (max - min) + min;
}

void fill_array(double* array, int size) {
  for (int i = 0; i < size; ++i)
    *(array+i) = d_rand(1.0, 2.0);
}

void print_array(double* array, int size) {
  for (int i = 0; i < size; ++i)
    printf("%lf ", *(array+i));
  printf("\n");
}

void swap(double* first, double* second) {
  double tmp = *first;
  *first = *second;
  *second = tmp;
}

bool is_equal(double a, double b) {
	return fabs(a-b) < 1e-5;
}

void selection_sort(double *arr, int size) {
  int k;
  for (int i = 0; i < size-1; i++) {
    k = i;
    for (int j = i + 1; j < size; j++)
    if(arr[j] < arr[k])
        k = j;
    swap(arr+k, arr+i);
   }
}

void append_if_prev_not_equal(double** res, int* result_size, int* last_idx, double* val) {
	double* result = *res;
	if (!is_equal(result[*last_idx-1], *val)) {
		if (*last_idx == *result_size) {
			*result_size += 1;
			*res = realloc(*res, *result_size * sizeof(double));
		}
		// TODO : check realloc errors

		result[*last_idx] = *val;
		++(*last_idx);
	}
}

// assumes a, b are sorted
double* one_two(double* a, int a_size, double* b, int b_size, int* result_size) {
	*result_size = 1;

	double* result = (double*) malloc(sizeof(double) * (*result_size));

	if (!result)
		return NULL;

	bool first_arr_shorter = a_size < b_size;

	double* first = first_arr_shorter? a : b;
	double* second = first_arr_shorter? b : a;

	if (*first < *second) {
		result[0] = *first;
		++first;
	}
	else {
		result[0] = *second;
		++second;
	}

	int idx = 1;
	//printf("aned = %p, bend = %p\n", a+a_size, b+b_size);
	// iterating till any of the arrays ends
	while(first != a+a_size && second != b+b_size) {
		//printf("first=%p, sec=%p\n", first, second);
		if (*first < *second)
			append_if_prev_not_equal(&result, result_size, &idx, first++);
		else
			append_if_prev_not_equal(&result, result_size, &idx, second++);
	}

	while(first != a+a_size)
		append_if_prev_not_equal(&result, result_size, &idx, first++);

	while(second != b+b_size)
		append_if_prev_not_equal(&result, result_size, &idx, second++);

	return result;
}


int main() {
  srand(time(NULL));

  double arr_first[SIZE_ONE];
  double arr_sec[SIZE_TWO];

  fill_array(arr_first, SIZE_ONE);
  fill_array(arr_sec, SIZE_TWO);
  puts("After filling:");
  print_array(arr_first, SIZE_ONE);
  print_array(arr_sec, SIZE_TWO);

  selection_sort(arr_first, SIZE_ONE);
  selection_sort(arr_sec, SIZE_TWO);
  puts("After sorting:");
  print_array(arr_first, SIZE_ONE);
  print_array(arr_sec, SIZE_TWO);

  puts("Joined:");
  int res_size;
	double* res = one_two(arr_first, SIZE_ONE, arr_sec, SIZE_TWO, &res_size);
  print_array(res, SIZE_ONE+SIZE_TWO);
  free(res);

  return 0;
}
