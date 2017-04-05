CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: print_arr mult_matrix mult_matrix2 up2low first_upper compare_str

print_arr:print_arr.c
	$(CC) $(CFLAGS) -o print_arr print_arr.c

mult_matrix: mult_matrix.c
	$(CC) $(CFLAGS) -o mult_matrix mult_matrix.c

mult_matrix2: mult_matrix2.c
	$(CC) $(CFLAGS) -o mult_matrix2 mult_matrix2.c

up2low: up2low.c
	$(CC) $(CFLAGS) -o up2low up2low.c

first_upper: first_upper.c
	$(CC) $(CFLAGS) -o first_upper first_upper.c

compare_str: compare_str.c
	$(CC) $(CFLAGS) -o compare_str compare_str.c

clean: print_arr mult_matrix mult_matrix2 up2low first_upper compare_str
	rm print_arr mult_matrix mult_matrix2 up2low first_upper compare_str
