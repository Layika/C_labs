#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

char rand_chr();

int main() {
    srand(time(NULL));

    char rand_string[SIZE];
    char random = rand_chr();

    char* idx = rand_string;
    char* iter = rand_string;
    int count = 0;

    for (int i = 0; i < SIZE-1; ++i)
        rand_string[i] = rand_chr();
    rand_string[SIZE-1] = '\0';
    printf("Random string: %s\n", rand_string);
    printf("Random letter: %c\n", random);

    while ((idx = strchr(iter, random))) {
        ++count;
        iter = idx+1;
    }
    
    printf("%d occurences of that letter.\n", count);

    return 0;
}

char rand_chr() {
    return rand() % ('z'-'a'+1) + 'a';
}
