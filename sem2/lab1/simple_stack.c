#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define BAD_ELEM -1

void show(int*);
bool push(int*, int);
int pop(int*);

int main() {
  int lifo[SIZE];
  for (int i = 0; i < SIZE; ++i)
    lifo[i] = BAD_ELEM;
  show(lifo);                          // stack empty

  for (int i = 0; i < 6; ++i) {
    push(lifo, i);
    show(lifo);
  }

  for (int i = 7; i > 0; --i) {        // pops everything + 1 in order to check if handling empty stack is OK
    int popped = pop(lifo);
    if (popped != BAD_ELEM)
      printf("popped: %d\n", popped);
  }

  printf("\n");
  show(lifo);
  return 0;
}

void show(int* lifo) {
    if (lifo[0] == BAD_ELEM) {
      puts("Stack empty");
    }

    else {
      int i = 0;
      while (lifo[i] != BAD_ELEM) {
        printf("%d ", lifo[i]);
        ++i;
      }
      printf("\n");
    }
}

bool push(int* lifo, int num) {
  int* last;
  int i = 0;

  if (num == BAD_ELEM) {
    puts("Cannot push -1!");
    return false;
  }

  if (lifo[0] == BAD_ELEM) {
    lifo[0] = num;
    last = lifo;
  }

  else {
    while (lifo[i] != BAD_ELEM && (i < SIZE-1)) {
      last = lifo + i;
      //printf("lifo[%d] = %d\n", i, lifo[i]);
      ++i;
    }

    if (last - lifo == SIZE) {
      puts("Cannot insert more elements, stack full!");
      return false;
    }
    *(last + 1) = num;
  }
  return true;
}

int pop(int* lifo) {
  int i = 0;
  int* last;
  int popped;

  if (lifo[0] == BAD_ELEM) {
    puts("Cannot pop from empty stack!");
    return -1;
  }

  while (lifo[i] != BAD_ELEM) {
    last = lifo + i;
    ++i;
  }

  popped = *last;
  *last = BAD_ELEM;
  --last;

  return popped;
}
