CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: sort_qsort qsort_bsearch biggest_val vector_3d length_vector add_vectors scalar_mult mult_vector params_vector

sort_qsort: sort_qsort.c
	$(CC) $(CFLAGS) -o sort_qsort sort_qsort.c

qsort_bsearch: qsort_bsearch.c
	$(CC) $(CFLAGS) -o qsort_bsearch qsort_bsearch.c -lm

biggest_val: biggest_val.c
	$(CC) $(CFLAGS) -o biggest_val biggest_val.c -lm

vector_3d: vector_3d.c
	$(CC) $(CFLAGS) -o vector_3d vector_3d.c

length_vector: length_vector.c
	$(CC) $(CFLAGS) -o length_vector length_vector.c -lm

add_vectors: add_vectors.c
	$(CC) $(CFLAGS) -o add_vectors add_vectors.c

scalar_mult: scalar_mult.c
	$(CC) $(CFLAGS) -o scalar_mult scalar_mult.c

mult_vector: mult_vector.c
	$(CC) $(CFLAGS) -o mult_vector mult_vector.c

params_vector: params_vector.c
	$(CC) $(CFLAGS) -o params_vector params_vector.c -lm

clean: sort_qsort qsort_bsearch biggest_val vector_3d length_vector add_vectors scalar_mult mult_vector params_vector
	rm sort_qsort qsort_bsearch biggest_val vector_3d length_vector add_vectors scalar_mult mult_vector params_vector
