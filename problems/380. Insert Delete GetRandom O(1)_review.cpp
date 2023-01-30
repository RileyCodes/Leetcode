class RandomizedSet {

    unordered_map<int, int> m;
    vector<int> v;    
public:
    RandomizedSet() {
    }
    
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
        swap(v[v.size() - 1], v[m[val]]);
        v.pop_back();

        m[v[m[val]]] = m[val];
        m.erase(val);
        return true;
    }
    
    int getRandom() {
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