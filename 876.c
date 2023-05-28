struct ListNode {
    int val;
    struct ListNode *next;
};

#define middleNode middle_node
#define list_node ListNode

struct list_node *
middle_node(struct list_node *head)
{
	struct list_node *arr[100] = { NULL };
	int count = 0;

	struct list_node *p = head;
	while (p != NULL) {
		arr[count++] = p;
		p = p->next;
	}

	return arr[count/2];
}
