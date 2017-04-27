#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define SIZE 61
#define PATTERN_SIZE 3
#define PATTERNS 8
#define BLACK 'x'
#define WHITE '-'

#define CHECK(x, msg) if (!(x)) \
    do { \
        puts(msg); \
        exit(-1); \
    } while(0)

char* init_arr(size_t size, size_t pairs_count, ...) {
    size_t idx = 0;

    char* arr = malloc(sizeof(char) * size);
    CHECK(arr, "Error allocating memory!");

    va_list arg;
    va_start(arg, pairs_count);

    for(size_t i = 0; i < pairs_count; ++i) {
        char c = va_arg(arg, int);
        size_t n = va_arg(arg, size_t);

        size_t counter = 0;
        while ((idx < size) && (counter < n)) {
            arr[idx] = c;
            ++counter;
            ++idx;
        }
    }
    va_end(arg);

    return arr;
}

void display_automata(char* arr, size_t size) {
    for(size_t i = 0; i < size; ++i)
        printf("%c", arr[i]);
    printf("\n");
}

int simple_process(char* current, char* new_iteration, int size) {
    char a, b, c;
    int idx;

    char p1[PATTERN_SIZE] = { BLACK, BLACK, BLACK };
    char p2[PATTERN_SIZE] = { BLACK, BLACK, WHITE };
    char p3[PATTERN_SIZE] = { BLACK, WHITE, BLACK };
    char p4[PATTERN_SIZE] = { BLACK, WHITE, WHITE };
    char p5[PATTERN_SIZE] = { WHITE, BLACK, BLACK };
    char p6[PATTERN_SIZE] = { WHITE, BLACK, WHITE };
    char p7[PATTERN_SIZE] = { WHITE, WHITE, BLACK };
    char p8[PATTERN_SIZE] = { WHITE, WHITE, WHITE };

    char* patterns[PATTERNS] = { p1, p2, p3, p4, p5, p6, p7, p8 };
    char elems[PATTERNS] = { WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE };

    for (int i = 1; i < size; i += 1) {

        a = current[i-1];
        b = current[i];
        c = current[i+1];

        char pattern[PATTERN_SIZE] = { a, b, c };
        for (int j = 0; j < PATTERNS; ++j) {
            if (memcmp(pattern, patterns[j], PATTERN_SIZE) == 0)
                idx = j;
        }
        new_iteration[i] =  elems[idx];
    }

    if (memcmp(current, new_iteration, size) == 0)
        return 0; // checks for stable state
    memcpy(current, new_iteration, SIZE);
    return 1;
}

int process_automaton(char* current, char* new_iteration, int size) {
    char a, b, c;
    int idx;

    char p1[PATTERN_SIZE] = { BLACK, BLACK, BLACK };
    char p2[PATTERN_SIZE] = { BLACK, BLACK, WHITE };
    char p3[PATTERN_SIZE] = { BLACK, WHITE, BLACK };
    char p4[PATTERN_SIZE] = { BLACK, WHITE, WHITE };
    char p5[PATTERN_SIZE] = { WHITE, BLACK, BLACK };
    char p6[PATTERN_SIZE] = { WHITE, BLACK, WHITE };
    char p7[PATTERN_SIZE] = { WHITE, WHITE, BLACK };
    char p8[PATTERN_SIZE] = { WHITE, WHITE, WHITE };

    char* patterns[PATTERNS] = { p1, p2, p3, p4, p5, p6, p7, p8 };
    char elems[PATTERNS] = { WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE };

    for (int i = 0; i < size; i += 1) {

        if (i == 0) {
            a = current[size-2];
            b = current[i];
            c = current[i+1];
        }

        else if (i == size - 1) {
            a = current[size-1];
            b = current[0];
            c = current[1];
        }

        else {
            a = current[i-1];
            b = current[i];
            c = current[i+1];
        }

        char pattern[PATTERN_SIZE] = { a, b, c };
        for (int j = 0; j < PATTERNS; ++j) {
            if (memcmp(pattern, patterns[j], PATTERN_SIZE) == 0)
                idx = j;
        }
        new_iteration[i] =  elems[idx];
    }

    if (memcmp(current, new_iteration, size) == 0)
        return 0; // checks for stable state
    memcpy(current, new_iteration, SIZE);
    return 1;
}

int main() {

    char* current = init_arr(SIZE, 3, WHITE, 29, BLACK, 1, WHITE, 30);
    char* new_iteration = init_arr(SIZE, 1, WHITE, 59);
    display_automata(current, SIZE);

    size_t counter = 0;

    // constraints version below:
    /*while (counter++ < 100) {
        //printf("counter: %lu\n", counter);
        if (process_automaton(current, new_iteration, SIZE))
            display_automata(current, SIZE);
        else {
            display_automata(current, SIZE);
            break;
        }
    }*/

    // version with simple_process below:
    while (counter++ < 180) {
        if (simple_process(current, new_iteration, SIZE))
            display_automata(current, SIZE);
        else {
            display_automata(current, SIZE);
            break;
        }
    }

    free(current);
    free(new_iteration);

    return 0;
}
