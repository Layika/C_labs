#include <stdio.h>
#include <math.h>
#define SIZE 5

typedef double (*fptr)(double);

double logarithm(double x) {return log(x); }
double power(double x) { return x*x; }
double tangens(double x) { return tan(x); }
double sinus(double x) { return sin(x); }
double cosinus(double x) { return cos(x); }

fptr* find_biggest(fptr pointers[], int size, double val) {
    fptr* biggest = pointers;
    for (int i = 1; i < size; ++i) {
        if (pointers[i](val) > (*biggest)(val))
            biggest = &pointers[i];
    }
    return biggest;
}


int main() {
    char* names[] = { "logarithm", "power", "tangens", "sinus", "cosinus" };
    fptr pointers[SIZE] = { logarithm, power, tangens, sinus, cosinus };

    fptr* func = find_biggest(pointers, SIZE, 1.0);
    int idx = (func - pointers);
    printf("%s has the biggest value for x = 1.0, that value is: %lf.\n",  names[idx], (*func)(1.0));

    func = find_biggest(pointers, SIZE, 0.05);
    idx = (func - pointers);
    printf("%s has the biggest value for x = 0.05, that value is: %lf.\n",  names[idx], (*func)(0.05));

    return 0;
}
