#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int sum_rec(int* array, int* ptr);
int rand_int(int min, int max);

int main() {
  srand(time(NULL));

  int rand_num[SIZE];
  int* ptr = NULL;

  for (ptr = rand_num; ptr < rand_num + SIZE ; ++ptr) {
     *ptr = rand_int(7, 35);
     printf("p[%d] = %d\n", (int)(ptr - rand_num), *ptr);
   }
  printf("\n");

  int sum = sum_rec(rand_num, ptr);

  printf("sum = %d\n", sum);
  return 0;
}

int sum_rec(int* array, int* ptr) {
    if (ptr) {
      if (array == ptr-1)
        return *array;
      else
        return *array + sum_rec(array + 1, ptr);
    }
    else
      return 0;
}

int rand_int(int min, int max){
    return rand() % (max-min+1) + min;
}
