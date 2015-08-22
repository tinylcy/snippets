/* Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively? */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
} ;

class Solution {
public:
    void inOrder(TreeNode *root,vector<int> &nums){
        if(root!=NULL){
            if(root->left!=NULL){
                inOrder(root->left,nums);
            }
            nums.push_back(root->val);
            if(root->right!=NULL){
                inOrder(root->right,nums);
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        nums.clear();
        inOrder(root,nums);
        return nums;
    }
};

int main()
{
    TreeNode *node1=new TreeNode(1);
    TreeNode *node2=new TreeNode(2);
    TreeNode *node3=new TreeNode(3);
    node1->right=node2;
    node2->left=node3;
    Solution object;
    vector<int> nums=object.inorderTraversal(node1);
    for(unsigned int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
