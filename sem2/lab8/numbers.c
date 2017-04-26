#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define PATH "output.txt"

typedef union val {
    int integer;
    double real;
} val;

typedef struct number {
    char type;
    val* values;
} number;

void make_structs(number** numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        numbers[i] = malloc(size * sizeof(number));
        numbers[i]->values = malloc(sizeof(val));
    }
}

void free_structs(number** numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        free(numbers[i]->values);
        free(numbers[i]);
    }
}

int irand(int min, int max){
    return rand() % (max-min+1) + min;
}

double drand(double min, double max) {
    return ((double)rand()/RAND_MAX) * (max-min) + min;
}

void fill_structs(number** numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {

        if (irand(1, 2) % 2) {
            numbers[i]->type = 'i';
            numbers[i]->values->integer = irand(0, 20);
        }

        else {
            numbers[i]->type = 'd';
            numbers[i]->values->real = drand(0,20);
        }

    }
}

void print_numbers(number** numbers, size_t size) {
    printf("[");
    for (size_t i = 0; i < size; ++i) {

        if (numbers[i]->type == 'i')
            printf(" (%c, %d)", numbers[i]->type, numbers[i]->values->integer);
        else
            printf(" (%c, %.2lf)", numbers[i]->type, numbers[i]->values->real);
    }
    puts(" ]");
}

void write_numbers(number** numbers, size_t size) {
    FILE* f = fopen(PATH, "ab+");
    if (!f) {
        perror("Error opening a file!");
        exit(-1);
    }

    fwrite(numbers, sizeof(number) * size, 1, f);
    fclose(f);
}

void get_numbers(number** numbers, size_t size) {
    FILE* f = fopen(PATH, "rb");
    if (!f) {
        perror("Error opening a file!");
        exit(-1);
    }

    fread(numbers, sizeof(number) * size, 1, f);
}

int find_idx(number** numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (numbers[i]->type == 'd')
            return i;
    }
    return -1;
}
int cmp_di(const void* a, const void* b) {
    number* n1 = (number*)a;
    number* n2 = (number*)b;
    return ((const int)n2->type - ((const int)n1->type));
}

int cmp_int(const void* a, const void* b) {
    number* n1 = (number*)a;
    number* n2 = (number*)b;
    return ((const int)n1->values->integer - (const int)n2->values->integer);
}

int  cmp_dbl(const void* a, const void* b) {
    number* n1 = (number*)a;
    number* n2 = (number*)b;
    return (((const double)n1->values->real > (const double)n2->values->real) - ((const double)n2->values->real > (const double)n1->values->real));
}

void sort(number** numbers, size_t size) {
    qsort(numbers, size, sizeof(numbers[0]), cmp_di); // move ints to the front

    int idx = find_idx(numbers, size); // find idx where ints stop
    qsort(numbers, idx, sizeof(numbers[0]), cmp_int);
    qsort(numbers+idx, size-idx, sizeof(numbers[0]), cmp_dbl);
}

int main() {
    srand(time(NULL));

    number* numbers[SIZE];
    make_structs(numbers, SIZE);
    fill_structs(numbers, SIZE);
    print_numbers(numbers, SIZE);

    write_numbers(numbers, SIZE);

    /*number* read_numbers[SIZE];
    make_structs(read_numbers, SIZE);
    get_numbers(numbers, SIZE);
    print_numbers(read_numbers, SIZE);*/
    qsort(numbers, SIZE, sizeof(numbers[0]), cmp_di);
    print_numbers(numbers, SIZE);
    free_structs(numbers, SIZE);
    //free_structs(read_numbers, SIZE);

    return 0;
}
