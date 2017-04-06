#include <stdio.h>
#include <string.h>
#include <math.h>

int bisection(double (*f)(double), double min, double max, double* root, double eps);
double f1(double x);

int main() {

    puts("Counting for sin(x) in <-1, 1>");
    double (*f)(double) = sin;
    double min = -1;            // value we start searching at
    double max = 1;             // value we stop at
    double eps = 0.0;           // precision of the result
    double root;

    if (bisection(f, min, max, &root, eps))
      printf("Root found: x = %lf\n", root);
    else
      puts("No root here!");


    puts("Counting for f1(x) in <0, 8>:");
    f = f1;
    min = 0;
    max = 8;

    if (bisection(f, min, max, &root, eps))
      printf("Root found: x = %lf\n", root);
    else
      puts("No root here!");


    puts("Counting for f1(x) in <-1, 1>:");
    min = -1;
    max = 1;

    if (bisection(f, min, max, &root, eps))
      printf("Root found: x = %lf\n", root);
    else
      puts("No root here!");

    return 0;
}

int bisection(double (*f)(double), double min, double max, double* root, double eps) {
    if (f(min) * f(max) > 0)
        return 0;

    while (fabs(f(min) - f(max)) > eps) {
        double mid = (min + max)/2.0;

        if (f(min) * f(mid) < 0)
            max = mid;
        else
            min = mid;
    }
    *root = min;

    return 1;
}

double f1(double x) {
  //return x-8;
  return -1*x*x + 3*x +11;
}
