#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void print_string_array(char** arr, size_t elements);
char* min_string(char** arr, size_t elements);

int main() {
    char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter" };
  	size_t strings_len = sizeof(strings)/sizeof(*strings);

    /* The PRIuPTR macro (from <inttypes.h>) defines a decimal format for uintptr_t
    which should always be large enough that one can cast a size_t to it without truncating.
    Another way could be using printf with %zd (but not every compiler supports it)
    or casting strings_len to unsigned long. */
    printf("Number of elements in strings: %" PRIuPTR "\n", (uintptr_t)strings_len);

    print_string_array(strings, strings_len);

    char* smallest_string = min_string(strings,strings_len);
    printf("Smallest string: %s\n", smallest_string);

  	return 0;
}

void print_string_array(char** arr, size_t elements) {
    for (size_t i = 0; i < elements; ++i)
        printf("%s ", arr[i]);
    printf("\n");
}

char* min_string(char** arr, size_t elements) {
    char* smallest = arr[0];

    for (size_t i = 1; i < elements; ++i)
        if (strcmp(smallest, arr[i]) < 0)
            smallest = arr[i];
            
    return smallest;
}
