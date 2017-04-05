#include <stdio.h>
#include <stdbool.h>

#define OFFSET 32

bool is_space(char letter) {
  if (letter == 32)
    return true;
  return false;
}

bool is_lower(int letter) {
  if (letter >= 97 && letter <= 122)
    return true;
  return false;
}

char make_upper(char letter) {
  if (is_lower(letter))
    letter = letter - OFFSET;
  return letter;
}

char* first2upper(char* string) {
  if (string[0] != '\0') {
    char* ptr = string+1;
    *string = make_upper(*string);
    while (*(ptr) != '\0') {
      if (is_space(*(ptr-1)))
        *(ptr) = make_upper(*(ptr));
      ++ptr;
    }
  }
  return string;
}

int main() {
  char string[100] = "this is      a               sample text     ";
  printf("String: %s\n", string);

  printf("After conversion: %s\n", first2upper(string));
  return 0;
}
