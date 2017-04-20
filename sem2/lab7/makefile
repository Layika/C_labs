CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: sort_qsort qsort_bsearch biggest_val vector params_vector

sort_qsort: sort_qsort.c
	$(CC) $(CFLAGS) -o sort_qsort sort_qsort.c

qsort_bsearch: qsort_bsearch.c
	$(CC) $(CFLAGS) -o qsort_bsearch qsort_bsearch.c -lm

biggest_val: biggest_val.c
	$(CC) $(CFLAGS) -o biggest_val biggest_val.c -lm

vector: vector.c
	$(CC) $(CFLAGS) -o vector vector.c -lm

params_vector: params_vector.c
	$(CC) $(CFLAGS) -o params_vector params_vector.c -lm

clean: sort_qsort qsort_bsearch biggest_val vector params_vector
	rm sort_qsort qsort_bsearch biggest_val vector params_vector
