#ifndef DEBUG
#define DEBUG 0
#endif

#include <stdio.h>
#include <stdlib.h>

#if DEBUG
#define DPRINTF printf
#else
#define DPRINTF(...) {;}
#endif

/*
 * NOTE: The returned array must be malloced, assume caller calls free()
 */

#define fizzBuzz fizzbuzz

char *F = "Fizz";
char *B = "Buzz";
char *FB = "FizzBuzz";

char **
fizzbuzz(int n, int *return_size)
{
	*return_size = n;
	char **result;

	// Assuming malloc never fails
	result = malloc((sizeof (char *)) * n);

	int N;
	char *p;
	char flag;
	DPRINTF("\ni\tN\tflag\n");
	for (int i = 0; i < n; i++) {
		N = i+1;
		flag = (N % 3 == 0) + 2 * (N % 5 == 0);
		DPRINTF("%d\t%d\t%d\n", i, N, flag);
		switch (flag) {
			case 0:
				DPRINTF("\tneed %d characters\n", snprintf(NULL, 0, "%d", N));
				DPRINTF("\tallocating %d bytes\n", (sizeof (char)) * (snprintf(NULL, 0, "%d", N) + 1));
				result[i] = malloc((sizeof (char)) * (snprintf(NULL, 0, "%d", N) + 1));
				DPRINTF("\tallocated %d bytes\n",  (sizeof (char)) * (snprintf(NULL, 0, "%d", N) + 1));
				sprintf(result[i], "%d", N);
				DPRINTF("\t\"%s\"\n", result[i]);
				continue;
			case 1: result[i] = F;	continue;
			case 2: result[i] = B;	continue;
			case 3: result[i] = FB;	continue;
		}
	}

	return result;
}


int main(void) {
	int buf;
	char **res = fizzBuzz(17, &buf);
	DPRINTF("\ni\ttext\n");
	for (int i = 0; i < buf; i++)
		printf("%d\t\"%s\"\n", i, res[i]);
	return 0;
}
