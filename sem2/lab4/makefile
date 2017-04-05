CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c11

all: count_data2dim oneline_print arr_avg sum_arr diff_2dim

count_data2dim:count_data2dim.c
	$(CC) $(CFLAGS) -o count_data2dim count_data2dim.c

oneline_print: oneline_print.c
	$(CC) $(CFLAGS) -o oneline_print oneline_print.c

arr_avg: arr_avg.c
	$(CC) $(CFLAGS) -o arr_avg arr_avg.c

sum_arr: sum_arr.c
	$(CC) $(CFLAGS) -o sum_arr sum_arr.c

diff_2dim: diff_2dim.c
	$(CC) $(CFLAGS) -o diff_2dim diff_2dim.c

clean: count_data2dim oneline_print
	rm count_data2dim oneline_print arr_avg sum_arr diff_2dim
