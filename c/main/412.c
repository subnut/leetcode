#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/412.c"

int main(void) {
	int buf;
	char **res = fizzBuzz(17, &buf);
	for (int i = 0; i < buf; i++)
		printf("%d\t\"%s\"\n", i, res[i]);
	return 0;
}
