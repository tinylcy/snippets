/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 */

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL&&q!=NULL){
            return false;
        }
        if(p!=NULL&&q==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        bool isSameLeft=isSameTree(p->left,q->left);
        bool isSameRight=isSameTree(p->right,q->right);
        return isSameLeft&&isSameRight;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
