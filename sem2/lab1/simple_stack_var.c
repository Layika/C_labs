#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10

void show(int* lifo, int* occupated);
void push(int* lifo, int num, int* occupated);
int pop(int* lifo, int* occupated);

int main() {
  int lifo[SIZE];
  int occupated = 0;
  puts("Printing out empty stack:");
  show(lifo, &occupated);
  printf("\n");

  puts("Testing push:");
  for (int i = 0; i < SIZE; ++i) {
    push(lifo, i, &occupated);
  }
  show(lifo, &occupated);
  printf("\n");

  puts("Testing pushing to full stack:");
  push(lifo, 100, &occupated);
  printf("\n");

  puts("Testing pop:");
  while (occupated)
      printf("popped: %d\n", pop(lifo, &occupated));

  show(lifo, &occupated);
  printf("\n");

  return 0;
}

void show(int* lifo, int* occupated) {
    if (!(*occupated)) {
      puts("Stack empty");
    }
    else {
      for (int i = 0; i < *occupated; ++i)
        printf("%d ", lifo[i]);
      printf("\n");
    }
}

int pop(int* lifo, int* occupated) {
  int popped;

  --(*occupated);
  popped = lifo[*occupated];

  return popped;
}

void push (int* lifo, int num, int* occupated) {
  if (*occupated == SIZE) {
    puts("Stack full, cannot push!");
  }
  else {
    lifo[*occupated] = num;
    ++(*occupated);
  }
}
