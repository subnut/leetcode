#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/14.c"

int main(void) {
	char *strs[] = {
		"flower",
		"flow",
		"flight",
	};
	char *ans = longestCommonPrefix(strs, sizeof(strs)/sizeof(strs[0]));
	printf("%s\n", ans);
	free(ans);
}
