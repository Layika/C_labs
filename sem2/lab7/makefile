CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: sort_qsort qsort_bsearch biggest_val vector_3d vector_length add_vectors scalar_mult vector_mult vector_params

sort_qsort: sort_qsort.c
	$(CC) $(CFLAGS) -o sort_qsort sort_qsort.c

qsort_bsearch: qsort_bsearch.c
	$(CC) $(CFLAGS) -o qsort_bsearch qsort_bsearch.c -lm

biggest_val: biggest_val.c
	$(CC) $(CFLAGS) -o biggest_val biggest_val.c -lm

vector_3d: vector_3d.c
	$(CC) $(CFLAGS) -o vector_3d vector_3d.c

vector_length: vector_length.c
	$(CC) $(CFLAGS) -o vector_length vector_length.c -lm

add_vectors: add_vectors.c
	$(CC) $(CFLAGS) -o add_vectors add_vectors.c

scalar_mult: scalar_mult.c
	$(CC) $(CFLAGS) -o scalar_mult scalar_mult.c

vector_mult: vector_mult.c
	$(CC) $(CFLAGS) -o vector_mult vector_mult.c

vector_params: vector_params.c
	$(CC) $(CFLAGS) -o vector_params vector_params.c -lm

clean: sort_qsort qsort_bsearch biggest_val vector_3d vector_length add_vectors scalar_mult vector_mult vector_params
	rm sort_qsort qsort_bsearch biggest_val vector_3d vector_length add_vectors scalar_mult vector_mult vector_params
