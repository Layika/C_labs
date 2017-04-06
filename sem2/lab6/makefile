CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: smallest_str sort_str find_letter format find_root sum_or_sub

smallest_str:smallest_str.c
	$(CC) $(CFLAGS) -o smallest_str smallest_str.c

sort_str: sort_str.c
	$(CC) $(CFLAGS) -o sort_str sort_str.c

find_letter: find_letter.c
	$(CC) $(CFLAGS) -o find_letter find_letter.c

format: format.c
	$(CC) $(CFLAGS) -o format format.c -lm

find_root: find_root.c
	$(CC) $(CFLAGS) -o find_root find_root.c -lm

sum_or_sub: sum_or_sub.c
	$(CC) $(CFLAGS) -o sum_or_sub sum_or_sub.c

clean: smallest_str sort_str find_letter format find_root sum_or_sub
	rm smallest_str sort_str find_letter format find_root sum_or_sub
