#include <stdio.h>
#include <string.h>

int str_cmp(char* a, char*b) {
  while (*a && *b && *a == *b) {
    ++a;
    ++b;
  }
  return *a - *b;
}

int main() {
  char str_a[] = "aaaaaaaaaaaaaaa";
  char str_b[] = "bbbbbbbbbbbbbbb";
  char str_biga[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char str_smallb[] = "bbb";

  puts("Results:");
  printf("Same strings: %d\n", str_cmp(str_b, str_b));
  printf("Smaller: %d, %d\n", str_cmp(str_a, str_b), str_cmp(str_biga, str_smallb));
  printf("Bigger: %d, %d\n", str_cmp(str_b, str_a), str_cmp(str_smallb, str_a));
  return 0;
}
