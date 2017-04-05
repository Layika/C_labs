CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: float_dyn_arr count_floor sort_unique recursion

float_dyn_arr: float_dyn_arr.c
	$(CC) $(CFLAGS)-o float_dyn_arr float_dyn_arr float_dyn_arr.c

count_floor: count_floor.c
	$(CC) $(CFLAGS)-o count_floor float_dyn_arr count_floor.c

sort_unique: sort_unique.c
	$(CC) $(CFLAGS)-o sort_unique float_dyn_arr sort_unique.c -lm

recursion: recursion.c
	$(CC) $(CFLAGS)-o recursion float_dyn_arr recursion.c

clean: float_dyn_arr count_floor sort_unique recursion
	rm float_dyn_arr count_floor sort_unique recursion.c
