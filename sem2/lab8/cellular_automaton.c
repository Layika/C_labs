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

void print_arr(char* arr, size_t size) {
    for(size_t i = 0; i < size; ++i)
        printf("%c ", arr[i]);
    printf("\n");
}

void fill_arr(char* first, char* second, int size, size_t times) {
    char a, b, c;
    int idx;
    size_t counter = times;

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

    while (counter) {
        for (int i = 0; i < size; i += 1) {

            if (i == 0) {
                a = first[size-1];
                b = first[i];
                c = first[i+1];
            }

            else if (i == size - 1) {
                a = first[size-1];
                b = first[0];
                c = first[1];
            }

            else {
                a = first[i-1];
                b = first[i];
                c = first[i+1];
            }

            char pattern[PATTERN_SIZE] = { a, b, c };
            for (int j = 0; j < PATTERNS; ++j) {
                if (memcmp(pattern, patterns[j], PATTERN_SIZE) == 0)
                    idx = j;
            }
            second[i] =  elems[idx];
        }
        --counter;
        memcpy(first, second, SIZE);
        printf("%lu: ", counter);
        print_arr(first, SIZE);
    }
}

int main() {

    // char* first = init_arr(SIZE, 3, WHITE, 10, BLACK, 1, WHITE, 10);
    // char* second = init_arr(SIZE, 1, WHITE, 21);

    char* first = malloc(sizeof(char) * SIZE);
    if (!first) {
        perror("Error allocating memory!");
        exit(-1);
    }

    char* second = malloc(sizeof(char) * SIZE);
    if (!second) {
        perror("Error allocating memory!");
        exit(-1);
    }
    memset(first, WHITE, 10);
    memset(first+10, BLACK, 1);
    memset(first+11, WHITE, 10);

    memset(second, WHITE, 21);

    print_arr(first, SIZE);
    print_arr(second, SIZE);

    fill_arr(first, second, SIZE, TIMES);

    free(first);
    free(second);
    return 0;
}
