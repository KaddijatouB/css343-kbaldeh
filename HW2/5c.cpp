// Implementation of the solution for leetcode problem 106.
// Construct Binary Tree from Inorder and Postorder Traversal.

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
    //index that hold the post oder
    int postOderIdx;
    //sub function to serve as a checker method
    TreeNode* createBSTree(vector<int>& inorder,vector<int>& postorder,int start,int end){
        // if the staring index is greater than the end, then return null
        if(start > end ){
            return nullptr;
        }
        // The root of  the tree on post order list will pe at the last index
        TreeNode* root= new TreeNode(postorder[postOderIdx--]);
        //find the position of the root in the inorder list
        int pos;
        for(int i=start;i<=end;i++){
            if(root->val == inorder[i])
            {
                pos=i;
            }
        }
        //recursively build a tree
        root->right=createBSTree(inorder, postorder, pos + 1, end);
        root->left=createBSTree(inorder, postorder, start, pos - 1);
        //return the root
        return root;

    }
    // build tree method
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //set post oder index to the last element of the list
        postOderIdx = postorder.size() - 1;

        //check size = zero (possible case for an empty tree), return null
        if(inorder.size() == 0){
            return nullptr;
        }
        //return built tree
        return createBSTree(inorder,postorder, 0, inorder.size()-1);
    }
};