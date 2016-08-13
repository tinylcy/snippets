#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
	int value;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

struct BinaryTreeNode* construct(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder);
void preOrderTraverse(struct BinaryTreeNode*);        /*先序遍历*/
void postOrderTraverse(struct BinaryTreeNode*);        /*后序遍历*/

int main(void) {
	int preOrder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inOrder[8] = {4, 7, 2, 1, 5, 3, 8, 6};

	struct BinaryTreeNode *root = construct(preOrder, &preOrder[7], inOrder, &inOrder[7]);

	preOrderTraverse(root);
	printf("\n");
	postOrderTraverse(root);

	return 0;
}

struct BinaryTreeNode* construct(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder) {

	if(startPreOrder == NULL || startInOrder == NULL) {
		return NULL;
	}

	struct BinaryTreeNode *root = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	root->value = *startPreOrder;
	root->left = NULL;
	root->right = NULL;

	int leftLength = 0;
	int *inOrderPtr = startInOrder;
	while(root->value != *inOrderPtr && inOrderPtr <= endInOrder) {
		inOrderPtr++;
	}
	leftLength = inOrderPtr - startInOrder;

	if(*inOrderPtr != root->value) {
		return NULL;
	}

	// 注意要判断左右子树是否存在
	if(leftLength > 0) {
		root->left = construct(startPreOrder + 1, startPreOrder + leftLength, startInOrder, inOrderPtr - 1);
	}
	if(endInOrder - inOrderPtr > 0) { 
		root->right = construct(startPreOrder + leftLength + 1, endPreOrder, inOrderPtr + 1, endInOrder);
	}
	return root;
}


void postOrderTraverse(struct BinaryTreeNode *root) {
	if(root != NULL) {
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		printf("%d ", root->value);
	}
}

void preOrderTraverse(struct BinaryTreeNode *root) {
	if(root != NULL) {
		printf("%d ", root->value);
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
	}
}

