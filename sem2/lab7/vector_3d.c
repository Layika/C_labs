#include <stdio.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

void print_vector(vector v) {
    printf("[ %.1lf, %.1lf, %.1lf ]\n", v.x, v.y, v.z);
}

int main() {
    vector v1;
    vector v2;

    puts("Provide coordinates for v1:");
    printf(" x = ");
    scanf("%lf", &v1.x);
    printf(" y = ");
    scanf("%lf", &v1.y);
    printf(" z = ");
    scanf("%lf", &v1.z);
    print_vector(v1);

    puts("Provide coordinates for v2:");
    printf(" x = ");
    scanf("%lf", &v2.x);
    printf(" y = ");
    scanf("%lf", &v2.y);
    printf(" z = ");
    scanf("%lf", &v2.z);
    print_vector(v2);

    return 0;
}
