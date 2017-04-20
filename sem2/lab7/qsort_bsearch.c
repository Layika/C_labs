#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STRING_LENGTH 20

int  cmp_double(const void* a, const void* b) {
    return ((*(const double*)a > *(const double*)b) - (*(const double*)b > *(const double*)a ));
}

int cmp_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void print_double_arr(double* arr, size_t size) {
    printf("[ ");
    for (size_t i = 0; i < size; ++i)
        printf("%lf ", arr[i]);
    puts(" ]");
}

void print_strings_arr(char** arr, size_t size) {
    printf("[ ");
    for (size_t i = 0; i < size; ++i)
        printf("%s ", arr[i]);
    puts(" ]");
}

void sort_double_arr() {
    double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1.2, 43.0, 2.0, -4.7, 5.8, 0 };
    size_t len = sizeof(numbers) / sizeof(numbers[0]);

    puts("Before sorting double:");
    print_double_arr(numbers, len);

    puts("After sorting double:");
    qsort(numbers, len, sizeof(numbers[0]), cmp_double);
    print_double_arr(numbers, len);

    puts("Provide a number to find in numbers array:");
    double check;
    scanf("%lf", &check);
    if (bsearch(&check, numbers, len, sizeof(numbers[0]), cmp_double))
        printf("Numbers array contains %lf.\n", check);
}

void sort_strings_arr() {
    char* strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter" };
    size_t len = sizeof(strings) / sizeof(strings[0]);

    puts("Before sorting strings:");
    print_strings_arr(strings, len);

    puts("After sorting strings:");
    qsort(strings, len, sizeof(strings[0]), cmp_strings);
    print_strings_arr(strings, len);

    puts("Provide a string to find in array:");
    char check[STRING_LENGTH];
    char* key = check;    // without this we would need to malloc space for check or write different cmp func for bsearch
    scanf("%20s", check); // return strcmp((const char*)a, *(const char**)b);
    if (bsearch(&key, strings, len, sizeof(strings[0]), cmp_strings))
        printf("Strings array contains %s.\n", check);
}

int main() {
    sort_double_arr();
    sort_strings_arr();

    return 0;
}
