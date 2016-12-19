#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int m_nValue;
    struct BinaryTreeNode *m_pLeft;
    struct BinaryTreeNode *m_pRight;
};

void mirror(struct BinaryTreeNode *);
void preOrderTraverse(struct BinaryTreeNode *);

int main() {
    struct BinaryTreeNode *node1 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node2 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node3 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node4 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node5 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node6 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node7 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

    node1->m_nValue = 8;
    node2->m_nValue = 6;
    node3->m_nValue = 10;
    node4->m_nValue = 5;
    node5->m_nValue = 7;
    node6->m_nValue = 9;
    node7->m_nValue = 11;

    node1->m_pLeft = node2;
    node1->m_pRight = node3;
    node2->m_pLeft = node4;
    node2->m_pRight = node5;
    node3->m_pLeft = node6;
    node3->m_pRight = node7;
    node4->m_pLeft = node4->m_pRight = NULL;
    node5->m_pLeft = node4->m_pRight = NULL;
    node6->m_pLeft = node4->m_pRight = NULL;
    node7->m_pLeft = node4->m_pRight = NULL;

    preOrderTraverse(node1);
    printf("\n");
    mirror(node1);
    preOrderTraverse(node1);
    printf("\n");
    return 0;
}

void mirror(struct BinaryTreeNode *tree) {
    if(tree == NULL) {
        return;
    }
    struct BinaryTreeNode *left = tree->m_pLeft;
    struct BinaryTreeNode *right = tree->m_pRight;
    tree->m_pLeft = right;
    tree->m_pRight = left;
    mirror(tree->m_pLeft);
    mirror(tree->m_pRight);
}

void preOrderTraverse(struct BinaryTreeNode *tree) {
    if(tree != NULL) {
        printf("%d ", tree->m_nValue);
        preOrderTraverse(tree->m_pLeft);
        preOrderTraverse(tree->m_pRight);
    }
}
