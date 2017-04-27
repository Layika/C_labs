#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define SIZE 21
#define TIMES 100
#define PATTERN_SIZE 3
#define PATTERNS 8
#define BLACK 'x'
#define WHITE '-'

#define CHECK(x, msg) if (!(x)) \
    do { \
        puts(msg); \
        exit(-1); \
    } while(0)

void display_automata(char* arr, size_t size) {
    for(size_t i = 0; i < size; ++i)
        printf("%c ", arr[i]);
    printf("\n");
}

void process_automaton(char* current, char* new_iteration, int size) {
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
            a = current[size-1];
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
    memcpy(current, new_iteration, SIZE);
}

int main() {

    // char* current = init_arr(SIZE, 3, WHITE, 10, BLACK, 1, WHITE, 10);
    // char* new_iteration = init_arr(SIZE, 1, WHITE, 21);

    char* current = malloc(sizeof(char) * SIZE);
    CHECK(current, "Error allocating memory!");

    char* new_iteration = malloc(sizeof(char) * SIZE);
    CHECK(new_iteration, "Error allocating memory!");
    
    memset(current, WHITE, 10);
    memset(current+10, BLACK, 1);
    memset(current+11, WHITE, 10);

    memset(new_iteration, WHITE, 21);

    display_automata(current, SIZE);
    display_automata(new_iteration, SIZE);

    size_t counter = 0;
    while (counter++ < 100) {
        process_automaton(current, new_iteration, SIZE);
        display_automata(current, SIZE);
    }

    free(current);
    free(new_iteration);
    return 0;
}
