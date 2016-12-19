#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct BinaryTreeNode {
    int m_nValue;
    struct BinaryTreeNode *m_pLeft;
    struct BinaryTreeNode *m_pRight;
};

int hasSubTree(struct BinaryTreeNode *, struct BinaryTreeNode *);
int compareTwoTree(struct BinaryTreeNode *treeA, struct BinaryTreeNode *treeB);

int main() {
    struct BinaryTreeNode *treeA = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *treeB = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeA1 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeA2 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeA3 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeA4 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeB1= (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeB2 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

    treeA->m_nValue = 8;
    treeA->m_pLeft = nodeA1;
    treeA->m_pRight = nodeA2;
    nodeA1->m_nValue = 8;
    nodeA1->m_pLeft = nodeA3;
    nodeA1->m_pRight = nodeA4;
    nodeA2->m_nValue = 7;
    nodeA2->m_pLeft = nodeA2->m_pRight = NULL;
    nodeA3->m_nValue = 9;
    nodeA3->m_pLeft = nodeA3->m_pRight = NULL;
    nodeA4->m_nValue = 2;
    nodeA4->m_pLeft = nodeA4->m_pRight = NULL;

    treeB->m_nValue = 8;
    treeB->m_pLeft = nodeB1;
    treeB->m_pRight = nodeB2;
    nodeB1->m_nValue = 9;
    nodeB1->m_pLeft = nodeB1->m_pRight = NULL;
    nodeB2->m_nValue = 2;
    nodeB2->m_pLeft = nodeB2->m_pRight = NULL;

    int result = hasSubTree(treeA, treeB);
    printf("result = %d\n", result);

    return 0;
}

int hasSubTree(struct BinaryTreeNode *treeA, struct BinaryTreeNode *treeB) {
    if(treeA == NULL && treeB == NULL) {
        return TRUE;
    }
    if(treeA != NULL && treeB == NULL) {
        return FALSE;
    }
    if(treeB != NULL && treeA == NULL) {
        return FALSE;
    }
    int ret = FALSE;
    ret = compareTwoTree(treeA, treeB);
    if(ret == TRUE) {
        return TRUE;
    }
    ret = hasSubTree(treeA->m_pLeft, treeB);
    if(ret == TRUE) {
        return TRUE;
    }
    ret = hasSubTree(treeA->m_pRight, treeB);
    return ret;
}

int compareTwoTree(struct BinaryTreeNode *treeA, struct BinaryTreeNode *treeB) {
    if(treeA == NULL && treeB == NULL) {
        return TRUE;
    }
    if(treeA != NULL && treeB == NULL) {
        return FALSE;
    }
    if(treeB != NULL && treeA == NULL) {
        return FALSE;
    }
    if(treeA->m_nValue == treeB->m_nValue) {
        int left = compareTwoTree(treeA->m_pLeft, treeB->m_pLeft);
        int right = compareTwoTree(treeA->m_pRight, treeB->m_pRight);
        return left && right;
    } else {
        return FALSE;
    }
}
