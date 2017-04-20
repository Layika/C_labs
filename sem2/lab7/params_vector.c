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

void print_vector(vector* v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v->x, v->y, v->z);
}

double count_length(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

void write_length(params* array, int size) {
    for (int i = 0; i < size; ++i)
        array[i].len = count_length(array[i].v.x, array[i].v.y, array[i].v.z);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s, <size>\n", argv[0]);
        exit(-1);
    }

    int size = atoi(argv[1]);

    params* array = malloc(size * sizeof(params));
    for (int i = 0; i < size; ++i) {
        array[i].v.x = rand() % 10;
        array[i].v.y = rand() % 10;
        array[i].v.z = rand() % 10;
    }

    write_length(array, size);

    for(int i = 0; i < size; ++i) {
        print_vector(&(array[i].v));
        printf("len: %lf\n", array[i].len);
    }

    return 0;
}
