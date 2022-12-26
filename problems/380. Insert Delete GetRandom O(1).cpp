class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.count(val))
            return false;
        v.emplace_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val))
            return false;
        int swapedVal =  v[v.size() - 1];
        swap(v[m[val]], v[v.size() - 1]);
        m[swapedVal] = m[val];
        v.resize(v.size() - 1);
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        cout << v.size() << endl;
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */