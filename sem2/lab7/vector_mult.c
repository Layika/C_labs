#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v.x, v.y, v.z);
}

void mult(vector a, vector b, vector* c) {
    c->x = a.y*b.z - a.z*b.y;
    c->y = a.x*b.z - a.z*b.x;
    c->z = a.x*b.y - a.y*b.x;
}

int main() {
    vector v1;
    vector v2;
    vector res;

    puts("Vector v1:");
    v1.x = 1.0;
    v1.y = 3.0;
    v1.z = 6.0;
    print_vector(v1);

    puts("Vector v2:");
    v2.x = 4.5;
    v2.y = 4.0;
    v2.z = 7.0;
    print_vector(v2);

    puts("Vector multiplication:");
    mult(v1, v2, &res);
    print_vector(res);
    return 0;
}
