class Trie {
public:
    vector<Trie*> children;
    int value;
    int prefixCount;
    Trie() : children(26), value(0),prefixCount(0) {}
    
    void insert(string word) {
        Trie* cur = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->children[index])
                cur->children[index] = new Trie();
            cur = cur->children[index];
            ++cur->prefixCount;
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

    
    int countWordsStartingWith(string prefix) {
        Trie* cur = this;
        for(auto&& chr : prefix)
        {
            int index = chr % 26;
            if(!cur->children[index])
                return 0;
            cur = cur->children[index];
        }
        return cur->prefixCount;
    }
    
    void erase(string word) {
        Trie* cur = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!cur->children[index])
                return;
            cur = cur->children[index];
            if(cur-> prefixCount > 0)
                -- cur->prefixCount;

        }        
        if(cur->value > 0)
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