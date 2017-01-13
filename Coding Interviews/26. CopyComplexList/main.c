#include <stdio.h>
#include <stdlib.h>

struct ComplexListNode {
    int value;
    struct ComplexListNode *next;
    struct ComplexListNode *sibling;
};

struct ComplexListNode* cloneComplexList(struct ComplexListNode *head);

int main() {
    struct ComplexListNode* node1 = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
    struct ComplexListNode* node2 = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
    struct ComplexListNode* node3 = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
    struct ComplexListNode* node4 = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
    struct ComplexListNode* node5 = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));

    node1->value = 1;
    node1->next = node2;
    node1->sibling = node3;
    node2->value = 2;
    node2->next = node3;
    node2->sibling = node5;
    node3->value = 3;
    node3->next = node4;
    node3->sibling = NULL;
    node4->value = 4;
    node4->next = node5;
    node4->sibling = node2;
    node5->value = 5;
    node5->next = NULL;
    node5->sibling = NULL;

    struct ComplexListNode* node = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
    node = cloneComplexList(node1);
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }

    return 0;

}

struct ComplexListNode* cloneComplexList(struct ComplexListNode *head) {
    struct ComplexListNode *current = NULL;
    struct ComplexListNode *currentClone = NULL;
    if(head == NULL) {
        return NULL;
    }

    /* step1 */
    current = head;
    while(current != NULL) {
        currentClone = (struct ComplexListNode*)malloc(sizeof(struct ComplexListNode));
        currentClone->next = current->next;
        currentClone->value = current->value;
        current->next = currentClone;
        current = currentClone->next;
    }

    /* step2 */
    current = head;
    while(current != NULL) {
        if(current->sibling != NULL) {
            current->next->sibling = current->sibling->next;
        }
        current = current->next->next;
    }

    /* step3 */
    current = head;
    currentClone = head->next;
    struct ComplexListNode *newHead = NULL;
    newHead = currentClone;
    while(current != NULL) {
        current->next = current->next->next;
        if(currentClone->next != NULL) {
            currentClone->next = currentClone->next->next;
        } else {
            currentClone->next = NULL;
        }
        current = current->next;
        currentClone = currentClone->next;
    }

    return newHead;
}
