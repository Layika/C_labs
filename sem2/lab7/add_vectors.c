#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v.x, v.y, v.z);
}

vector sum_vectors(vector a, vector b) {
    vector sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    sum.z = a.z + b.z;
    return sum;
}

int main() {
    vector v1;
    vector v2;

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

    vector sum = sum_vectors(v1, v2);
    printf("Sum: ");
    print_vector(sum);
    return 0;
}
