#include <stdio.h>
#include <stdlib.h>

struct ListNode* findKthNodeFromEnd(struct ListNode*, int);

struct ListNode {
    int m_nValue;
    struct ListNode *m_pNext;
};

int main() {

    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node2->m_nValue = 2;
    node2->m_pNext = node3;
    node3->m_nValue = 3;
    node3->m_pNext = node4;
    node4->m_nValue = 4;
    node4->m_pNext = node5;
    node5->m_nValue = 5;
    node5->m_pNext = NULL;

    struct ListNode *result = NULL;

    int i;
    for(i = -10; i < 10; i++) {
        result = findKthNodeFromEnd(node1, i);
        if(result != NULL) {
            printf("i = %d, value = %d\n", i, result->m_nValue);
        } else {
            printf("i = %d, value = NULL\n", i);
        }
    }

    return 0;
}

/*
 * 1. 头节点为NULL。
 * 2. k大于节点总长度。
 * 3. k为非正数。
 */
struct ListNode* findKthNodeFromEnd(struct ListNode* head, int k) {
    struct ListNode* first;
    struct ListNode* second;
    first = head;
    second = NULL;
    int cnt = 0;

    while(cnt < k && first != NULL) {
        first = first->m_pNext;
        cnt++;
    }

    if(cnt != k) {
        return NULL;
    }

    second = head;

    while(first != NULL) {
        first = first->m_pNext;
        second = second->m_pNext;
    }

    return second;
}
