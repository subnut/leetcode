struct ListNode {
    int val;
    struct ListNode *next;
};

#define middleNode middle_node
#define list_node ListNode

struct list_node *
middle_node(struct list_node *head)
{
	struct list_node *A, *B;
	A = B = head;

	while (A->next) {
		B = B->next;
		A = A->next;
		if (A->next)
			A = A->next;
	}

	return B;
}
