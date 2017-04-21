#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

int main(){
    char pi_fmt[6] = {0};
    for (int i = 0; i < 7; i += 2){
	sprintf(pi_fmt, "%d", i);
	printf("FORMAT %%.%slf ->", pi_fmt);
	sprintf(pi_fmt, "%%1.%dlf%s", i, "\n");
	printf(pi_fmt, M_PI);
    }
}
