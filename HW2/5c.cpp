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
    int postind;
    //sub function to serve as a helper method, it takes in two int that represent the staring index and the end
    TreeNode* BSTree(vector<int>& inorder,vector<int>& postorder,int start,int end){
        if(start > end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[postind--]);
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
        postind = postorder.size()-1;
        return BSTree(inorder,postorder,0,inorder.size()-1);
    }
};
/**
* class Solution {
public:
     TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int InorderStart, int InorderEnd, int PostorderStart, int PostorderEnd)
    {
        if(InorderStart>InorderEnd)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[PostorderEnd]);
        int index;
        for(index=InorderStart;index<=InorderEnd;index++)
        {
            if(inorder[index]==postorder[PostorderEnd])
                break;
        }
        int rootIndex=index;
        int LeftPostOrderStart=PostorderStart;
        int LeftInorderStart= InorderStart;
        int LeftInorderEnd= rootIndex-1;
        int LeftPostOrderEnd= LeftPostOrderStart+ LeftInorderEnd-LeftInorderStart;
        root->left=helper(inorder,postorder,LeftInorderStart,LeftInorderEnd,LeftPostOrderStart,LeftPostOrderEnd);

        int RightPostOrderStart=LeftPostOrderEnd+1;
        int RightPostOrderEnd=PostorderEnd-1;
        int RightInorderStart=rootIndex+1;
        int RightInorderEnd= InorderEnd;
        root->right=helper(inorder, postorder,RightInorderStart,RightInorderEnd,RightPostOrderStart,RightPostOrderEnd );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
*/