#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode *convertTreeToList(struct BinaryTreeNode *root);
void convert(struct BinaryTreeNode *root);

int main() {
    struct BinaryTreeNode *node1 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node2 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node3 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node4 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node5 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node6 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *node7 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

    struct BinaryTreeNode *nodeA = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeB = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeC = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    struct BinaryTreeNode *nodeD = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

    node1->value = 10;
    node1->left = node2;
    node1->right = node3;
    node2->value = 6;
    node2->left = node4;
    node2->right = node5;
    node3->value = 14;
    node3->left = node6;
    node3->right = node7;
    node4->value = 4;
    node4->left = node4->right = NULL;
    node5->value = 8;
    node5->left = node5->right = NULL;
    node6->value = 12;
    node6->left = node6->right = NULL;
    node7->value = 16;
    node7->left = node7->right = NULL;

    struct BinaryTreeNode *node = NULL;
    node = convertTreeToList(node1);
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->right;
    }

    printf("\n");

    nodeA->value = 10;
    nodeA->left = nodeB;
    nodeA->right = NULL;
    nodeB->value = 6;
    nodeB->left = nodeC;
    nodeB->right = nodeD;
    nodeC->value = 4;
    nodeC->left = nodeC->right = NULL;
    nodeD->value = 8;
    nodeD->left = nodeD->right = NULL;

    node = convertTreeToList(nodeA);
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->right;
    }

    return 0;
}

struct BinaryTreeNode *convertTreeToList(struct BinaryTreeNode *root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return NULL;
    }
    struct BinaryTreeNode *min = root;
    while(min->left != NULL) {
        min = min->left;
    }
    convert(root);

    return min;
}

void convert(struct BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }
    struct BinaryTreeNode *leftMax = root->left;
    struct BinaryTreeNode *rightMin = root->right;
    while(leftMax != NULL && leftMax->right != NULL) {
        leftMax = leftMax->right;
    }
    while(rightMin != NULL && rightMin->left != NULL) {
        rightMin = rightMin->left;
    }
    convert(root->left);
    convert(root->right);
    if(leftMax != NULL) {
        leftMax->right = root;
        root->left = leftMax;
    }
    if(rightMin != NULL) {
        rightMin->left = root;
        root->right = rightMin;
    }
}

