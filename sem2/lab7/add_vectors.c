#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector* v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v->x, v->y, v->z);
}

vector sum_vectors(vector a, vector b) {
    vector sum = { a.x + b.x, a.y + b.y, a.z + b.z };
    return sum;
}

int main() {
    vector v1 = { 1.0, 3.0, 6.0 };
    vector v2 = { 4.5, 4.0, 7.0 };

    puts("Vector v1:");
    print_vector(&v1);

    puts("Vector v2:");
    print_vector(&v2);

    vector sum = sum_vectors(v1, v2);
    printf("Sum: ");
    print_vector(&sum);

    return 0;
}
