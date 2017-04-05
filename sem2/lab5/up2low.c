#include <stdio.h>
#include <stdbool.h>

#define OFFSET 32

bool is_upper(int letter) {
  if (letter >= 65 && letter <= 90)
    return true;
  return false;
}

char make_lower(char letter) {
  if (is_upper(letter))
    letter = letter + OFFSET;
  return letter;
}

int main() {
  char string[] = "ALA MA KOTA";
  printf("String: %s\n", string);

  int idx = 0;
  while (string[idx] != '\0') {
    string[idx] = make_lower(string[idx]);
    idx++;
  }

  printf("String: %s\n", string);

  return 0;
}
