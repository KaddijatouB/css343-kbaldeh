// Implementation of the solution for leetcode problem 106.
// Construct Binary Tree from Inorder and Postorder Traversal

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
    int idx;
    //sub function to serve as a helper method, it takes in two int that represent the staring index and the end
    TreeNode* BSTree(vector<int>& inorder,vector<int>& postorder,int start,int end){
        if(start > end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[idx--]);
        int pos;
        for(int i = start; i <= end; i++){
            if(node->val == inorder[i]){
                pos = i;
            }
        }
        node->right = BSTree(inorder,postorder,pos+1,end);
        node->left = BSTree(inorder,postorder,start,pos-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = postorder.size() - 1;
        return BSTree(inorder,postorder,0,inorder.size()-1);
    }
};
