/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *   The left subtree of a node contains only nodes with keys less than the node's key.
 *   The right subtree of a node contains only nodes with keys greater than the node's key.
 *   Both the left and right subtrees must also be binary search trees.
 *
 * confused what "{1,#,2,3}" means?
 *
 * OJ's Binary Tree Serialization:
 *
 * The serialization of a binary tree follows a level order traversal,
 * where '#' signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 *
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> nums;

    void inOrderTraverse(TreeNode *root){
        if(root!=NULL){
            if(root->left!=NULL){
                inOrderTraverse(root->left);
            }
            nums.push_back(root->val);
            if(root->right!=NULL){
                inOrderTraverse(root->right);
            }
        }
    }

    bool judge(vector<int> &nums){
        if(nums.size()==0||nums.size()==1){
            return true;
        }
        for(unsigned int i=1;i<nums.size();i++){
            if(!(nums[i]>nums[i-1])){
                return false;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        nums.clear();
        inOrderTraverse(root);
        return judge(nums);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
