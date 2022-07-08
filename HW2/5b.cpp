// Implementation of the solution for leetcode problem 114.
// Flatten Binary Tree to Linked List
// Traverse vs. sub-problems

/**
* Definition for a binary tree node.
*/
/**
 * struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        //take the root node as the current node
        TreeNode* currNode = root;
        TreeNode* previousNode = nullptr;
        //loop through the tree
        while(currNode != nullptr){
            //if the left node is not null
            if(currNode->left != nullptr){
                //set the previous node to be the left node
                previousNode = currNode->left;
                //check the right side till the end
                while(previousNode->right != nullptr){
                    previousNode = previousNode->right;
                }
                //swap positions
                previousNode->right = currNode->right;
                currNode->right = currNode->left;
                currNode->left = nullptr;
            }
            currNode = currNode->right;
        }
    }
};