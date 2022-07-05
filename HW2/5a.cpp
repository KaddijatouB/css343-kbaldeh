/**
 * Implementation of the solution for leetcode problem 116.
 * Populating Next Right Pointers in Each Node
 * Level order traversal
 */

#include <queue>
using std::queue;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        //check if the root is not null
        if(root != nullptr){
            //use queue and push the root first
            queue<Node*> listQueue;
            listQueue.push(root);

            while(!listQueue.empty()){
                int size = listQueue.size();
                Node* prev = nullptr;
                for(int i = 0; i < size; ++i){
                    //set a node to the next element in the queue
                    Node* node = listQueue.front();
                    //remove the element from the queue
                    listQueue.pop();
                    //if the left node is not null, add it to queue
                    if(node->left != nullptr){
                        listQueue.push(node->left);
                    }
                    //if the right node is not null, add to queue
                    if(node->right != nullptr){
                        listQueue.push(node->right);
                    }
                    //
                    if(prev != nullptr){
                        prev->next = node;
                    }
                    //
                    prev = node;
                }
            }
        }
        return root;
    }
};