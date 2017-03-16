#include <stdio.h>
#include <stdlib.h>

void print_row(int* row, int size, int height) {
  for (int space = 0; space < height-size; ++space)
    printf(" ");
  for (int i = 0; i < size; ++i) {
    printf("%d ", row[i]);
  }
  printf("\n");
}

void print_array(int* arr, int size) {
      printf("array = [");
      for(int i=0; i<size; ++i)
        printf("%d, ", arr[i]);
      printf("]\n");
}


int main() {
  int height;

  do {
    puts("Provide height:");
    scanf("%d", &height);
  } while (getchar() != '\n');

  int* row = NULL;

  for (int size = 1; size <= height; ++size) {
    row = realloc(row, size*sizeof(int));

    row[0] = row[size-1] = 1;

    int prev_value = row[0];
    int tmp;

    for(int i = 1; i < size-1; ++i) {
      tmp = row[i];
      row[i] = prev_value + row[i];
      prev_value = tmp;
    }

    print_row(row, size, height);
  }
  return 0;
}
