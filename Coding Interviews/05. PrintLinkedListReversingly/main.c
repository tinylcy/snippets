#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int m_nKey;
	struct ListNode *m_pNext;
};

void print_linkedlist_reversingly(struct ListNode*);

int main(void) {
	struct ListNode *node1 = (struct ListNode*)malloc(sizeof(ListNode));
	struct ListNode *node2 = (struct ListNode*)malloc(sizeof(ListNode));
	struct ListNode *node3 = (struct ListNode*)malloc(sizeof(ListNode));
	node1->m_nKey = 1;
	node1->m_pNext = node2;
	node2->m_nKey = 2;
	node2->m_pNext = node3;
	node3->m_nKey = 3;
	node3->m_pNext = NULL;

	print_linkedlist_reversingly(node1);

	return 0;
}

void print_linkedlist_reversingly(struct ListNode* head) {
	if(head == NULL) {
		return;
	}

	if(head->m_pNext != NULL) {
		print_linkedlist_reversingly(head->m_pNext);
	}

	printf("%d ", head->m_nKey);
}