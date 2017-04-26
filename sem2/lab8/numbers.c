#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHECK(x, msg) if (!(x)) \
    do { \
        puts(msg); \
        exit(-1); \
    } while(0)

#define CHECK_ALLOC(ptr) CHECK(ptr, "Couldn't allocate memory. Aborting.")


#define SIZE 20
#define PATH "output.txt"
#define EPS 0.0001

typedef union val {
    int integer;
    double real;
} val;

typedef struct number {
    char type;
    val value;
} number;

int irand(int min, int max){
    return rand() % (max-min+1) + min;
}

double drand(double min, double max) {
    return ((double)rand()/RAND_MAX) * (max-min) + min;
}

void fill_structs(number* numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {

        if (irand(1, 2) % 2) {
            numbers[i].type = 'i';
            numbers[i].value.integer = irand(0, 20);
        }

        else {
            numbers[i].type = 'd';
            numbers[i].value.real = drand(0,20);
        }

    }
}

void print_numbers(number* numbers, size_t size) {
    printf("[");
    for (size_t i = 0; i < size; ++i) {

        if (numbers[i].type == 'i')
            printf(" (%c, %d)", numbers[i].type, numbers[i].value.integer);
        else
            printf(" (%c, %.2lf)", numbers[i].type, numbers[i].value.real);
    }
    puts(" ]");
}

void write_numbers(number* numbers, size_t size) {
    FILE* f = fopen(PATH, "wb");
    if (!f) {
        perror("Error opening a file!");
        exit(-1);
    }

    fwrite(numbers, sizeof(number), size, f);
    fclose(f);
}

void get_numbers(number* numbers, size_t size) {
    FILE* f = fopen(PATH, "rb");
    if (!f) {
        perror("Error opening a file!");
        exit(-1);
    }

    fread(numbers, sizeof(number), size, f);
}

int find_idx(number* numbers, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (numbers[i].type == 'd')
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
    return ((const int)n1->value.integer - (const int)n2->value.integer);
}

int  cmp_dbl(const void* a, const void* b) {
    number* n1 = (number*)a;
    number* n2 = (number*)b;

    double v = (((const double)n1->value.real > (const double)n2->value.real) - ((const double)n2->value.real > (const double)n1->value.real));
    return v < EPS? 0 : v;
}

void sort(number* numbers, size_t size) {
    qsort(numbers, size, sizeof(numbers[0]), cmp_di); // move ints to the front

    int idx = find_idx(numbers, size); // find idx where ints stop
    qsort(numbers, idx, sizeof(numbers[0]), cmp_int);
    qsort(numbers+idx, size-idx, sizeof(numbers[0]), cmp_dbl);
}

int main() {
    srand(time(NULL));

    number* numbers = malloc(SIZE * sizeof(number));
    CHECK_ALLOC(numbers);

    fill_structs(numbers, SIZE);
    print_numbers(numbers, SIZE);

    write_numbers(numbers, SIZE);

    number* read_numbers = malloc(SIZE * sizeof(number));
    CHECK_ALLOC(read_numbers);

    get_numbers(read_numbers, SIZE);
    print_numbers(read_numbers, SIZE);

    sort(numbers, SIZE);
    print_numbers(numbers, SIZE);
    free(numbers);
    free(read_numbers);

    return 0;
}
