#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
  unsigned int size = 0;

  while (size < 1 || size > 100000) {
    puts("Provide a number between 1 and 100000:");
    scanf("%u", &size);
    while (getchar() != '\n');
  }

  unsigned int* primes = malloc(sizeof(int) * size);

  for (unsigned int i = 2; i < size; ++i)
    primes[i] = true;
  primes[0] = primes[1] = false;


  for (unsigned int i = 2; i < size; ++i) {
    if (primes[i]) {
      for (unsigned int j = i; i * j < size; ++j)
        primes[i * j] = false;
      }
  }

  printf("\nPrime numbers in range 1 to %d are: \n", size);
  for (unsigned int i = 0; i < size; i++) {
    if (primes[i])
      printf("%d\n", i);
    }

  free(primes);
  return 0;
}
