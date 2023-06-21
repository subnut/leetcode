#define node ListNode
#define isPalindrome is_palindrome
bool is_palindrome(struct node *head) {
	struct node *arr[100000];
	int count = 0;

	struct node *p = head;
	do p = (arr[count++] = p)->next; while (p != NULL);

	struct node **A, **B;
	A = arr; B = arr + count - 1;
	do if ((*A)->val != (*B)->val) return false;
	while (++A < --B);

	return true;
}
