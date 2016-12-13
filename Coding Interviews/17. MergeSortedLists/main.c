#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int m_nValue;
    struct ListNode *m_pNext;
};

struct ListNode* merge(struct ListNode *listA, struct ListNode *listB);
struct ListNode* mergeRecursive(struct ListNode *listA, struct ListNode *listB);
void printList(struct ListNode *head);

int main() {
    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node8 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node9 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node10 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->m_nValue = 1;
    node1->m_pNext = node3;
    node2->m_nValue = 2;
    node2->m_pNext = node4;
    node3->m_nValue = 3;
    node3->m_pNext = node5;
    node4->m_nValue = 4;
    node4->m_pNext = node6;
    node5->m_nValue = 5;
    node5->m_pNext = node7;
    node6->m_nValue = 6;
    node6->m_pNext = node8;
    node7->m_nValue = 7;
    node7->m_pNext = node9;
    node8->m_nValue = 8;
    node8->m_pNext = node10;
    node9->m_nValue = 9;
    node9->m_pNext = NULL;
    node10->m_nValue = 10;
    node10->m_pNext = NULL;

    struct ListNode *head = NULL;

    // head = merge(node1, node2);
    head = mergeRecursive(node1, node2);
    printList(head);

	// free operation
    return 0;
}

struct ListNode* merge(struct ListNode *listA, struct ListNode *listB) {
    if(listA == NULL && listB == NULL) {
        return NULL;
    }
    if(listA == NULL && listB != NULL) {
        return listB;
    }
    if(listB == NULL && listA != NULL) {
        return listA;
    }

    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;
    p = listA;
    q = listB;

    if(p->m_nValue < q->m_nValue) {
        head = p;
        p = p->m_pNext;
    } else {
        head = q;
        q = q->m_pNext;
    }
    tail = head;

    while(p != NULL && q != NULL) {
        if(p->m_nValue < q->m_nValue) {
            tail->m_pNext = p;
            tail = p;
            p = p->m_pNext;
        } else {
            tail->m_pNext = q;
            tail = q;
            q = q->m_pNext;
        }
    }

    if(p != NULL) {
        tail->m_pNext = p;
    }
    if(q != NULL) {
        tail->m_pNext = q;
    }

    return head;
}

struct ListNode* mergeRecursive(struct ListNode *listA, struct ListNode *listB) {
    if(listA == NULL && listB == NULL) {
        return NULL;
    }
    if(listA != NULL && listB == NULL) {
        return listA;
    }
    if(listB != NULL && listA == NULL) {
        return listB;
    }
    struct ListNode *head = NULL;
    if(listA->m_nValue < listB->m_nValue) {
        head = listA;
        head->m_pNext = mergeRecursive(listA->m_pNext, listB);
    } else {
        head = listB;
        head->m_pNext = mergeRecursive(listA, listB->m_pNext);
    }

    return head;

}

void printList(struct ListNode *head) {
    if(head == NULL) {
        return;
    }
    while(head != NULL) {
        printf("%d ", head->m_nValue);
        head = head->m_pNext;
    }
    printf("\n");
}
