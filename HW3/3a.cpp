// 133. Clone Graph
// [BFS]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //if the graph is not empty
        if (node != nullptr){
            Node* neo = new Node(node->val);
            //use unordered_map to track of new nodes
            unordered_map<Node*,Node*> tracker;
            tracker[node] = neo;
            //Declare a queue to store all the nodes connected to nodeVal
            queue<Node*> list;
            //Insert node to queue
            list.push(node);
            //loop through till the list is empty
            while (!list.empty()) {
                // extract first element in list
                Node* current = list.front();
                //then remove from the list
                list.pop();
                //check for the adjacent nodes
                for (auto i: current->neighbors){
                    if(tracker.find(i) == tracker.end()) {
                        // then create copy of node
                        tracker[i] = new Node(i->val);
                        list.push(i);
                    }
                    // in current node push adjcant node
                    tracker[current] -> neighbors.push_back(tracker[i]);
                }
            }
            //return the unordered map containing clones
            return tracker[node];
        }
        //else return a null pointer
        return nullptr;
    }
};

