#include <stdio.h>
#include <string.h>

#define SIZE 81
#define MAX_ROWS 20

void sort_strings(char* data[], int num);
void swap_str(char* str1, char* str2);

int main() {
  char data[MAX_ROWS][SIZE];
  char* strings_ptr[MAX_ROWS];
  int counter = 0;

  printf("Provide at most %d rows.\n", MAX_ROWS);
  printf("When finished press enter at the beginning of a new line.\n");

  while (counter < MAX_ROWS && gets(data[counter]) != NULL && data[counter][0] != '\0') {
     strings_ptr[counter] = data[counter];
     counter++;
  }

  sort_strings(strings_ptr, counter);
  puts("\nHere's your sorted list:");
  for (int i = 0; i < counter; ++i)
     puts(strings_ptr[i]);
  return 0;
}


void sort_strings(char* data[], int elements) {
  char tmp[SIZE];
  for (int i = 0; i < elements; ++i) {
     for (int j = 0; j < elements-1; ++j) {
        if (strcmp(data[i], data[j]) > 0) {
            strcpy(tmp, data[i]);
            strcpy(data[i], data[j]);
            strcpy(data[j], tmp);
        }
     }
  }
}
