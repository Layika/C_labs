#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector* v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v->x, v->y, v->z);
}

void mult(vector a, vector b, vector* c) {
    c->x = a.y*b.z - a.z*b.y;
    c->y = a.x*b.z - a.z*b.x;
    c->z = a.x*b.y - a.y*b.x;
}

int main() {
    vector v1 = { 1.0, 3.0, 6.0 };
    vector v2 = { 4.5, 4.0, 7.0 };
    vector res;

    puts("Vector v1:");
    print_vector(&v1);

    puts("Vector v2:");
    print_vector(&v2);

    puts("Vector multiplication:");
    mult(v1, v2, &res);
    print_vector(&res);
    return 0;
}
