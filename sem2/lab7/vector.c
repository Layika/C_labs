#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector* v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v->x, v->y, v->z);
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

int main() {
    vector v1, v2;

    get_coordinates(&v1);
    print_vector(&v1);

    get_coordinates(&v2);
    print_vector(&v2);

    return 0;
}
