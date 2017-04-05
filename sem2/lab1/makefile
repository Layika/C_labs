CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g

all: arr_sum_recursive simple_stack simple_stack_var reverse_arr float_data_idx float_data_ptr sort_even_odd move_right

arr_sum_recursive: arr_sum_recursive.c
	$(CC) $(CFLAGS) -o arr_sum_recursive -std=c11 arr_sum_recursive.c

simple_stack: simple_stack.c
	$(CC) $(CFLAGS) -o simple_stack -std=c11 simple_stack.c

simple_stack_var: simple_stack_var.c
	$(CC) $(CFLAGS) -o simple_stack_var -std=c11 simple_stack_var.c

reverse_arr: reverse_arr.c
	$(CC) $(CFLAGS) -o reverse_arr -std=c11 reverse_arr.c

float_data_idx: float_data_idx.c
	$(CC) $(CFLAGS) -o float_data_idx -std=c11 float_data_idx.c -lm

float_data_ptr: float_data_ptr.c
	$(CC) $(CFLAGS) -o float_data_ptr -std=c11 float_data_ptr.c -lm

sort_even_odd: sort_even_odd.c
	$(CC) $(CFLAGS) -o sort_even_odd -std=c11 sort_even_odd.c

move_right: move_right.c
	$(CC) $(CFLAGS) -o move_right -std=c11 move_right.c

clean:
	rm arr_sum_recursive simple_stack simple_stack_var reverse_arr float_data_ptr float_data_idx sort_even_odd move_right
