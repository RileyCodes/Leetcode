

class Node{
public:
    vector<Node*> nodes;
    bool isEnd;
    Node() : nodes(26), isEnd(false){}
};


class Trie {
    Node* root = new Node();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->nodes[index])
                cur->nodes[index] = new Node();
            cur = cur->nodes[index];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->nodes[index])
                return false;
            cur = cur->nodes[index];
        }
        return cur && cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto&& chr : prefix)
        {
            int index = chr % 26;
            if(!cur->nodes[index])
                return false;
            cur = cur->nodes[index];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */