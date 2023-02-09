class Trie {
public:
    vector<Trie*> children;
    int value;
    Trie() : children(26), value(0) {}
    
    void insert(string word) {
        Trie* cur = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->children[index])
                cur->children[index] = new Trie();
            cur = cur->children[index];
        }
        ++cur->value;
    }
    
    int countWordsEqualTo(string word) {
        Trie* cur = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->children[index])
                return 0;
            cur = cur->children[index];
        }
        return cur ? cur->value : 0;
    }

    int countTrie(Trie* node)
    {
        if(!node)
            return 0;
        int count = node->value;
        for(int i = 0; i < 26; ++i)
        {
            if(node->children[i])
                count += countTrie(node->children[i]);
        }
        return count;
    }
    
    int countWordsStartingWith(string prefix) {
        Trie* cur = this;
        for(auto&& chr : prefix)
        {
            int index = chr % 26;
            if(!cur->children[index])
                return 0;
            cur = cur->children[index];
        }
        return countTrie(cur);
    }
    
    void erase(string word) {
        Trie* cur = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->children[index])
                return;
            cur = cur->children[index];
        }        
        if(cur->value >= 0)
            --cur->value;                    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */