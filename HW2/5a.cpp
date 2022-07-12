//Implementation of the solution for leetcode problem 116.
//Populating Next Right Pointers in Each Node.
//Level order traversal.

/**
 *  Definition for a Node.
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
 */
class Solution {
public:
    Node* connect(Node* root) {
        //check if the root is not null
        if(root != nullptr){
            //use queue to creat a list
            queue<Node*> listQueue;
            listQueue.push(root);
            //loop through while the root in front of the queue is not empty
            while(!listQueue.empty()){
                int size = listQueue.size();
                Node* prev = nullptr;
                //loop through size of the queue
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
                    //add node to the next position
                    if(prev != nullptr){
                        prev->next = node;
                    }
                    // set previous to be the node
                    prev = node;
                }
            }
        }
        return root;
    }
};