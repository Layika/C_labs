all: pascal.c
	gcc -Wall -Wextra -Wpedantic -g -o pascal -std=c11 pascal.c
	gcc -Wall -Wextra -Wpedantic -g -o arr_2dim -std=c11 arr_2dim.c
	gcc -Wall -Wextra -Wpedantic -g -o sieve -std=c11 sieve.c

pascal: pascal.c
	gcc -Wall -Wextra -Wpedantic -g -o pascal -std=c11 pascal.c

arr_2dim: arr_2dim.c
	gcc -Wall -Wextra -Wpedantic -g -o arr_2dim -std=c11 arr_2dim.c

sieve: sieve.c
	gcc -Wall -Wextra -Wpedantic -g -o sieve -std=c11 sieve.c

clean: pascal arr_2dim sieve
	rm pascal arr_2dim sieve
