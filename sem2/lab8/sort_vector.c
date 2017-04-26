#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct params {
    vector v;
    double len;
} params;

void print_vectors(params* arr, int size) {
    for (int i = 0; i < size; ++i)
        printf("[ %.1lf, %.1lf, %.1lf ]      length: %.2lf\n", arr[i].v.x, arr[i].v.y, arr[i].v.z, arr[i].len);
    printf("\n");
}

double count_length(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

void write_length(params* array, int size) {
    for (int i = 0; i < size; ++i)
        array[i].len = count_length(array[i].v.x, array[i].v.y, array[i].v.z);
}

int  cmp_len(const void* a, const void* b) {
    params* a1 = (params*)a;
    params* a2 = (params*)b;
    return (((const double)a1->len > (const double)a2->len) - ((const double)a2->len > (const double)a1->len ));
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc < 2 || atoi(argv[1]) == 0) {
        printf("Usage: %s, <size > 0>\n", argv[0]);
        exit(-1);
    }

    int size = atoi(argv[1]);

    params* array = malloc(size * sizeof(params));
    if (array == NULL) {
        puts("Allocation failed!");
        exit(-1);
    }

    for (int i = 0; i < size; ++i) {
        array[i].v.x = rand() % 10;
        array[i].v.y = rand() % 10;
        array[i].v.z = rand() % 10;
    }
    write_length(array, size);

    puts("Sorted by length:");
    qsort(array, size, sizeof(array[0]), cmp_len);
    print_vectors(array, size);

    puts("Provide a size to find:");
    double check;
    scanf("%lf", &check);
    if (bsearch(&check, array, size, sizeof(array[0]), cmp_len))
        printf("Numbers array contains %lf.\n", check);

    free(array);

    return 0;
}
