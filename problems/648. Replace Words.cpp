class Trie  
{
    vector<Trie*> children;
    vector<int> indexTo;
public:
    Trie() : children(26){}

    void insert(string& word, int ansIndex)
    {
        Trie* node = this;
        for(auto&& chr : word)
        {
            int index = chr % 26;
            if(!node->children[index])
                node->children[index] = new Trie();
            node = node->children[index];
            node->indexTo.emplace_back(ansIndex);
        }
    }
    vector<int> findPrefix(string& prefix)
    {
        Trie* node = this;
        for(auto&& chr : prefix)
        {
            int index = chr % 26;
            if(!node->children[index])
                return vector<int>();
            node = node->children[index];
        }
        return node->indexTo;
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        vector<string> ans;
        string word;
        for(int i = 0; i <= sentence.size(); ++i)
        {
            
            if(i == sentence.size() || sentence[i] == ' ')
            {
                trie.insert(word,ans.size());
                ans.emplace_back(word);
                word.clear();
                continue;
            }
            word += sentence[i];
        }
        unordered_map<int, string> m;
        for(auto&& str : dictionary)
        {
            vector<int> indexTo = trie.findPrefix(str);
            
            for(auto index : indexTo)
            {
                if(m.count(index) == 0 || m[index].size() > str.size())
                    m[index] = str;
            }
                
                
        }

        string finalAns;
        for(int i = 0; i < ans.size(); ++i)
        {
            if(m.count(i))
            {
                ans[i] = m[i];
            }
                
            finalAns += ans[i];
            finalAns += " ";
        }
        finalAns.pop_back();

        return finalAns;
    }
};