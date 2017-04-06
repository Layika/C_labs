#include <stdio.h>

int sum(int* x, int* y);
int sub(int*x, int* y);
int invoke(int x, int y, int (*f)(int* x, int* y));

int main() {
    int x = 5;
    int y = 12;

    printf("%d + %d = %d\n", x, y, invoke(x, y, sum));
    printf("%d - %d = %d\n", x, y, invoke(x, y, sub));

    return 0;
}


int sum(int* x, int* y) {
    return *x + *y;
}

int sub(int* x, int* y) {
    return *x - *y;
}

int invoke(int x, int y, int (*f)(int* x, int* y)) {
    return f(&x, &y);
}
