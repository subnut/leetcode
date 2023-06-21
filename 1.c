#include <stdlib.h>
#include <stdio.h>

#if DEBUG
#define dprintf printf
#else
#define dprintf(...) {;}
#endif

/*
 * NOTE: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *buf = calloc(*returnSize, sizeof (int));

	int *fast, *slow;
	fast = nums;
	dprintf("slow\tfast\tsum\ttarget\n");
	while (fast < nums + numsSize) {
		slow = fast;
		while (++slow < nums + numsSize) {
			dprintf("%i\t%i\t%i\t%i\n", *slow, *fast, *slow + *fast, target);
			if (*slow + *fast == target)
				goto found;
		}
		fast++;
	}

found:
	buf[0] = slow - nums;
	buf[1] = fast - nums;
	return buf;
}

int main(void) {
	int nums[] = {3,2,4};
	int retsize;
	int*ret = twoSum(nums, 3, 6, &retsize);
	printf("[%i, %i]\n",ret[0],ret[1]);
	free(ret);
}
