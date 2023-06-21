#include <stdlib.h>

#include "debug.h"
#include "src/1.c"

int main(void) {
	int nums[] = {3,2,4};
	int retsize;
	int*ret = twoSum(nums, 3, 6, &retsize);
	printf("[%i, %i]\n",ret[0],ret[1]);
	free(ret);
}
