class WordDictionary {
public:
    vector<WordDictionary*> children;
    bool isEnd;

    WordDictionary() : children(26), isEnd(false){}
    
    void addWord(string word) {
        WordDictionary* cur = this;
        for(auto&& chr : word)
        {
            if(!cur->children[chr % 26])
                cur->children[chr % 26] = new WordDictionary();
            cur = cur->children[chr % 26];
        }
        cur->isEnd = true;
    }
    

    bool search(WordDictionary* dict, string& word, int index)
    {
        int i = index;
        if(index >= word.size())
            return dict->isEnd;
            
        if(word[i] == '.')
        {
            for(int j = 0; j <26 ;++j)
            {
                if(dict->children[j])
                {
                    if(search(dict->children[j], word, i + 1))
                        return true;
                }
            }
            return false;
        }
        if(!dict->children[word[i] % 26])
            return false;
        return search(dict->children[word[i] % 26], word, i + 1);
    }

    bool search(string word) {
        return search(this, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */