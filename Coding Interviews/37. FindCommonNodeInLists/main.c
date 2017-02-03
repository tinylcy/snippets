#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int value;
	struct ListNode *next;
};

struct ListNode* findFirstCommonNode(struct ListNode *, struct ListNode *);
unsigned int length(struct ListNode *);
unsigned int gap_abs(int, int);

int main(void) {
	struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node7 = (struct ListNode *)malloc(sizeof(struct ListNode));

	node1->value = 1;
	node1->next = node2;
	node2->value = 2;
	node2->next = node3;
	node3->value = 3;
	node3->next = node6;
	node4->value = 4;
	node4->next = node5;
	node5->value = 5;
	node5->next = node6;
	node6->value = 6;
	node6->next = node7;
	node7->value = 7;
	node7->next = NULL;

	struct ListNode *common = findFirstCommonNode(node1, node2);
	while(common != NULL) {
		printf("%d ", common->value);
		common = common->next;
	}
	printf("\n");
	return 0;
}

struct ListNode* findFirstCommonNode(struct ListNode* listA, struct ListNode *listB) {
	if(listA == NULL || listB == NULL) {
		return NULL;
	}
	struct ListNode *longer = listA;
	struct ListNode *shorter = listB;
	int lenA = length(listA);
	int lenB = length(listB);
	// printf("lenA = %d, lenB = %d\n", lenA, lenB);
	if(lenA < lenB) {
		longer = listB;
		shorter = listA;
	}
	int gap = gap_abs(lenA, lenB);
	while(gap > 0) {
		longer = longer->next;
		gap--;
	}

	while(longer != NULL && shorter != NULL) {
		if(longer == shorter) {
			return longer;
		}
		longer = longer->next;
		shorter = shorter->next;
	}
	return NULL;
}

unsigned int length(struct ListNode *head) {
	if(head == NULL) {
		return 0;
	}
	unsigned int len = 0;
	while(head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

unsigned int gap_abs(int x, int y) {
	return x < y ? y - x : x - y;
}