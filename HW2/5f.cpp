//  Implementation of the solution for leetcode problem 450.
//   Delete Node in a BST:
//        -No child.
//        -Only 1 child.
//        -Two children  (inorder findMinimum/predecessor has no children or has 1 child).

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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode() : val(0), left(nullptr), right(nullptr) {}

     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // check if the BST is not empty
        if(root != nullptr){
            //then check if the value to delete is present at the root
            if(root->val == key){
                //if the node has no children, delete the node
                if(root->left == nullptr && root->right == nullptr)   {
                    delete root;
                    return nullptr;
                }
                //if the node has only a left child
                if(root->left != nullptr && root->right == nullptr)   {
                    TreeNode *temp = root->left;
                    delete root;
                    return temp;
                }
                //if the node has only a right child
                if(root->left == nullptr && root->right !=nullptr )   {
                    TreeNode *temp = root->right;
                    delete root;
                    return temp;
                }
                //if the node has both left and right
                if(root->left != nullptr && root->right != nullptr )  {
                    //find predecessor to swap values with root
                    int lower = findMinimum(root->right);
                    root->val = lower;
                    //recursively delete the right
                    root->right = deleteNode(root->right, lower);
                    return root;
                }
            }
            //check the left side if the key value is less than the root value
            if( root->val > key ){
                root->left = deleteNode(root->left,key);
                return root;
            }
            //check the right side if the key value is less than the root value
            else if(root->val < key ){
                root->right = deleteNode(root->right,key);
                return root;
            }
        }
       //otherwise, return root
        return root;
    }

    //sub-function to find the minimum value
    int findMinimum(TreeNode *root)      {
        while(root->left !=nullptr )
            root = root->left;
        return root->val;
    }
};
