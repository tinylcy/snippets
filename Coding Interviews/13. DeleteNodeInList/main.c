#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int m_nValue;
    struct ListNode *m_pNext;
};

struct ListNode* deleteNodeInList(struct ListNode*, struct ListNode*);
void printNodeList(struct ListNode*);

int main(void) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->m_nValue = 0;
    head->m_pNext = node1;
    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node2->m_nValue = 2;
    node2->m_pNext = node3;
    node3->m_nValue = 3;
    node3->m_pNext = node4;
    node4->m_nValue = 4;
    node4->m_pNext = NULL;

    head = deleteNodeInList(head, head);
    printNodeList(head);

    return 0;
}

/*
 * 1. 只有一个节点，且head == p。
 * 2. p不是尾节点，将p的下一个节点的值复制到p节点，删除p的下一个节点。
 * 3. p是尾节点，采用从头节点开始遍历的方式删除尾节点。
 */
struct ListNode* deleteNodeInList(struct ListNode *head, struct ListNode *p) {
    if(head == NULL || p == NULL) {
        return head;
    }
    if(head == p && head->m_pNext == NULL) {
        free(p);
        return NULL;
    }
    struct ListNode *q = NULL;
    q = p->m_pNext;
    if(q != NULL) {
        p->m_nValue = q->m_nValue;
        p->m_pNext = q->m_pNext;
        free(q);
    } else {
        q = head;
        while(q->m_pNext != p) {
            q = q->m_pNext;
        }
        q->m_pNext = NULL;
        free(p);
    }

    return head;
}

void printNodeList(struct ListNode *head) {
    if(head == NULL) {
        return;
    }
    while(head != NULL) {
        printf("%d ", head->m_nValue);
        head = head->m_pNext;
    }
    printf("\n");
}
