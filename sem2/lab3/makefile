CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: pascal arr_2dim sieve

pascal: pascal.c
	$(CC) $(CFLAGS) -o pascal pascal.c

arr_2dim: arr_2dim.c
	$(CC) $(CFLAGS) -o arr_2dim arr_2dim.c

sieve: sieve.c
	$(CC) $(CFLAGS) -o sieve sieve.c

clean: pascal arr_2dim sieve
	rm pascal arr_2dim sieve
