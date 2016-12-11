#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int m_nKey;
    struct ListNode *m_pNext;
};

struct ListNode* reverseList(struct ListNode*);
struct ListNode* reverseListRecursive(struct ListNode*);
void printList(struct ListNode*);

int main() {
    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->m_nKey = 1;
    node1->m_pNext = node2;
    node2->m_nKey = 2;
    node2->m_pNext = node3;
    node3->m_nKey = 3;
    node3->m_pNext = node4;
    node4->m_nKey = 4;
    node4->m_pNext = node5;
    node5->m_nKey = 5;
    node5->m_pNext = NULL;

    struct ListNode *head = NULL;
    head = reverseList(node1);
    printList(head);
    head = reverseListRecursive(head);
    printList(head);

    // free operations

    return 0;
}

struct ListNode* reverseList(struct ListNode *head) {
    if(head == NULL) {
        return NULL;
    }
    struct ListNode *newHead = NULL;
    struct ListNode *afterHead = NULL;

    newHead = head;
    head = head->m_pNext;
    newHead->m_pNext = NULL;
    while(head != NULL) {
        afterHead = head->m_pNext;
        head->m_pNext = newHead;
        newHead = head;
        head = afterHead;
    }

    return newHead;
};

struct ListNode* reverseListRecursive(struct ListNode *head) {
     if(head == NULL) {
        return NULL;
     }
     if(head->m_pNext == NULL) {
        return head;
     }

     struct ListNode *newHead = NULL;
     struct ListNode *afterHead = NULL;
     afterHead = head->m_pNext;
     newHead = reverseListRecursive(afterHead);
     afterHead->m_pNext = head;
     head->m_pNext = NULL;

     return newHead;
};

void printList(struct ListNode *head) {
    if(head == NULL) {
        return;
    }
    while(head != NULL) {
        printf("%d ", head->m_nKey);
        head = head->m_pNext;
    }
    printf("\n");
}
