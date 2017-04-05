#include <stdio.h>

int count_nth(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 6;
  else
    return 3 + count_nth(n-1);
}

int main() {
  printf("0: %d, 1: %d, 2: %d, 3: %d, 4: %d\n", count_nth(0), count_nth(1), count_nth(2), count_nth(3), count_nth(4));
  return 0;
}
