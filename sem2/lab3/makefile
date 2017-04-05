CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g

all: pascal arr_2dim sieve

pascal: pascal.c
	$(CC) $(CFLAGS) -o pascal -std=c11 pascal.c

arr_2dim: arr_2dim.c
	$(CC) $(CFLAGS) -o arr_2dim -std=c11 arr_2dim.c

sieve: sieve.c
	$(CC) $(CFLAGS) -o sieve -std=c11 sieve.c

clean: pascal arr_2dim sieve
	rm pascal arr_2dim sieve
