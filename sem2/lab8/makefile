CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: clients numbers sort_vector cellular_automaton

clients: clients.c
	$(CC) $(CFLAGS) -o clients clients.c

numbers: numbers.c
	$(CC) $(CFLAGS) -o numbers numbers.c

sort_vector: sort_vector.c
	$(CC) $(CFLAGS) -o sort_vector sort_vector.c -lm

cellular_automaton: cellular_automaton.c
	$(CC) $(CFLAGS) -o cellular_automaton cellular_automaton.c

clean: clients numbers sort_vector cellular_automaton
	rm clients numbers sort_vector cellular_automaton
