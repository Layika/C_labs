#include <stdio.h>
#include <stdlib.h>

int* floor_fun(double* first, double* second) {
  int* res = malloc(sizeof(int));
  if (!res)
    return NULL;
  *res = (int)(*first * *second);
  return res;
}

int main() {
  double first = 10.334;
  double second = 4.567;

  int* res = floor_fun(&first, &second);
  if (!res) {
    puts("Try again, allocation failed.");
    return -1;
  }

  else {
    printf("%lf * %lf = %lf, floor = %d\n", first, second, first*second, *res);
    free(res);
    return 0;
  }
}
