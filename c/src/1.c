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
