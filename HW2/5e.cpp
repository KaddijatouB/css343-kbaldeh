// Implementation of the solution for leetcode problem 701.
// Insert into a Binary Search Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //check if the root is null, then insert
        if(root == nullptr){
            root = new TreeNode(val);
        }else{
            //if the root is not null and the value is less than the value at the root
            if(root->val > val){
                root->left = insertIntoBST(root->left, val);
            }
            //if the value is greater than the value at the root
            if(root->val < val){
                root->right = insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};