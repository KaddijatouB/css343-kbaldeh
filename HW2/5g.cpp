//Implementation of the solution for leetcode problem 208.
//Implement Trie (Prefix Tree)

//create a node struct with array of 26 alphabets
const int ALPHA_SIZE = 26;
struct Node{
    Node* child[ALPHA_SIZE];
    bool endOfWord;
};

class Trie {
private:
    //create a root node
    Node *root;
    // Returns new trie node that is initialized
    Node* findNode(){
        Node* ptr =  new Node;
        ptr->endOfWord = false;

        for (int i = 0; i < ALPHA_SIZE; i++){
            ptr->child[i] = nullptr;
        }
        return ptr;
    }

public:
    Trie() {
        //create a new root node;
        root = new Node();
    }
    // Inserts the string word into the trie.
    void insert(string word) {
        Node* node = root;
        //loop through the given word and check each character
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            //if the alphabet does not exist in the trie, then add
            if(!node->child[idx]){
                node->child[idx] = findNode();
            }
            // moves to the reference trie
            node = node->child[idx];
        }
        node->endOfWord = true;
    }
    // Returns true if the string word is in the trie and false otherwise.
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(!node->child[index]){
                return false;
            }
            node = node->child[index];
        }
        // return true or false for the end
        return node->endOfWord;
    }
    // Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            int index = prefix[i] - 'a';
            if(!node->child[index]){
                return false;
            }
            node = node->child[index];
        }
        return true;
    }
};