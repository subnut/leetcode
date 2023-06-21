/*
 * NOTE: The returned array must be malloced, assume caller calls free()
 */

#define fizzBuzz fizzbuzz

static void Fizz	(char **str) { memcpy(*str = calloc(5, sizeof (char)), "Fizz"	, 5); }
static void Buzz	(char **str) { memcpy(*str = calloc(5, sizeof (char)), "Buzz"	, 5); }
static void FizzBuzz	(char **str) { memcpy(*str = calloc(9, sizeof (char)), "FizzBuzz"	, 9); }
static void Self	(char **str, int n)
{
	char len = 2;	// for trailing NUL
	if (n > 9)	len++;
	if (n > 99)	len++;
	if (n > 999)	len++;
	if (n > 9999)	len++;
	/* We know that 0 < n <= 10000 */
	sprintf(*str = calloc(len, sizeof (char)), "%d", n);
}

char **
fizzbuzz(int n, int *return_size)
{
	*return_size = n;

	char **result;
	result = calloc(n, sizeof (char *));

	int N;
	char *p;
	char flag;

	for (int i = 0; i < n; i++) {
		N = i+1;
		flag = (N % 3 == 0) + 2 * (N % 5 == 0);
		switch (flag) {
			case 0: Self(&result[i], N);	continue;
			case 1: Fizz(&result[i]);	continue;
			case 2: Buzz(&result[i]);	continue;
			case 3: FizzBuzz(&result[i]);	continue;
		}
	}

	return result;
}
