class MapSum {
public:
//
    vector<MapSum*> children;
    int val = 0;
    int prefixVal = 0;
    bool isEnd = false;

    MapSum() : children(256) {}

    int getKey(string key)
    {
        MapSum* cur = this;
        for(auto chr : key)
        {
            if(!cur->children[chr])
                return 0;
            cur = cur->children[chr];
        }        

        return (cur && cur->isEnd)? cur->val : 0;
    }
    
    void insert(string key, int val) {
        MapSum* cur = this;

        int oldValue = getKey(key);
        int diff = val - oldValue;

        for(auto chr : key)
        {
            if(!cur->children[chr])
                cur->children[chr] = new MapSum();
            cur = cur->children[chr];
            cur->prefixVal += diff;
        }
        cur->val = val;
        cur->isEnd = true;
    }
    
    int sum(string prefix) {
        MapSum* cur = this;
        for(auto chr : prefix)
        {
            if(!cur->children[chr])
                return 0;
            cur = cur->children[chr];
        }        

        return cur? cur->prefixVal : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */