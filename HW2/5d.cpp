//   [BST operations]
//  Implementation of the solution for leetcode problem 98.
// Validate Binary Search Tree

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
    //sub-function to validate the tree
    bool validateTree(TreeNode* root, TreeNode* minValue, TreeNode* maxValue) {
        // first check if the tree is empty then it is valid
        if (root == nullptr){
            return true;
        }
        // Compare the current node value so that it is within range of min and max values
        if (minValue != nullptr) {
            if (root->val <= minValue->val) {
                return false;
            }
        }
        if (maxValue != nullptr ) {
            if (root->val >= maxValue->val) {
                return false;
            }
        }
        // return the validated left and right subtree if all conditions are met
        bool okay = validateTree(root->right, root, maxValue) && validateTree(root->left, minValue, root);;
        return okay;

    }
    //function to validate
    bool isValidBST(TreeNode* root){
        //call the sub-function of validateTree for each tree
        return validateTree(root, nullptr, nullptr);
    }
};



