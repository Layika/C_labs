#include <stdio.h>
#include <math.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector* v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n\n", v->x, v->y, v->z);
}

void get_coordinates(vector* v) {
    puts("Provide coordinates for vector:");
    printf(" x = ");
    scanf("%lf", &v->x);
    printf(" y = ");
    scanf("%lf", &v->y);
    printf(" z = ");
    scanf("%lf", &v->z);
}

vector sum_vectors(vector a, vector b) {
    vector sum = { a.x + b.x, a.y + b.y, a.z + b.z };
    return sum;
}

double count_length(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

void mult(vector a, vector b, vector* c) {
    c->x = a.y*b.z - a.z*b.y;
    c->y = a.x*b.z - a.z*b.x;
    c->z = a.x*b.y - a.y*b.x;
}

double scalar(vector* a, vector* b) {
    return a->x*b->x + a->y*b->y + a->z*b->z;
}

int main() {
    vector v1, v2;

    get_coordinates(&v1);
    print_vector(&v1);
    get_coordinates(&v2);
    print_vector(&v2);

    vector sum = sum_vectors(v1, v2);
    printf("Sum: ");
    print_vector(&sum);

    printf("Vector v1 length: %lf.\n\n", count_length(v1.x, v1.y, v1.z));

    puts("Vector multiplication:");
    vector res;
    mult(v1, v2, &res);
    print_vector(&res);

    printf("Scalar multiplication: %.1lf.\n", scalar(&v1, &v2));

    return 0;
}
