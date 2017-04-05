#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_f(float min, float max) {
    return ((float)rand()/RAND_MAX) * (max - min) + min;
}

int main() {
  srand(time(NULL));
  size_t size;

  do {
    puts("Provide size:");
    scanf("%lu", &size);
  } while (getchar() != '\n');

  float* array = malloc(size*sizeof(float));

  for (unsigned int i = 0; i < size; ++i)
    *(array+i) = rand_f(230.0f, 341.0f);
  for (float* iter = array; iter < array+size; ++iter)
    printf("%f ", *iter);
  printf("\n");
  free(array);
  return 0;
}
