class LFUCache {
public:

    int minFeq = -1;
    struct MetaData
    {
        int feq, key, value;
    };
    int capacity;
    unordered_map<int, list<MetaData>::iterator> keyToCache;
    unordered_map<int, list<MetaData>> feqListMap;

    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        //cout << "get " << key << endl;
        auto it = keyToCache.find(key);
        if(it == keyToCache.end())
            return -1;
        int value = it->second->value;
        int feq = it->second->feq;
        //cout << "erase:"  << it->second->key << endl;
        feqListMap[feq].erase(it->second);
        //cout << "done get" << endl;
        if(minFeq == feq && feqListMap[feq].size() == 0)
            ++minFeq;
        ++feq;
        feqListMap[feq].emplace_front(MetaData{feq, key , value});
        keyToCache[key] = feqListMap[feq].begin();
        return value;
    }
    
    void put(int key, int value) {
        //cout << "put " << key << " " << value << endl;
        auto it = keyToCache.find(key);
        if(it != keyToCache.end())
        {
            int feq =  it->second->feq;
            //cout << "erase:"  << it->second->key << endl;
            feqListMap[feq].erase(it->second);
            if(minFeq == feq && feqListMap[feq].size() == 0)
                ++minFeq;            
            ++feq;
            feqListMap[feq].emplace_front(MetaData{feq, key , value});
            keyToCache[key] = feqListMap[feq].begin();
            return;
        }
        
        if(capacity <= 0)
        {
            //cout << "size:" << feqListMap[minFeq].size() << endl;
            //cout << "erase:" << feqListMap[minFeq].back().key << " minFeq " <<  minFeq << endl;
            keyToCache.erase(feqListMap[minFeq].back().key);
            feqListMap[minFeq].pop_back();
            ++capacity;
            //cout << "done" << endl;
        }
        minFeq = 1;
        --capacity;
        
        feqListMap[minFeq].emplace_front(MetaData{minFeq, key , value});
        keyToCache[key] = feqListMap[minFeq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */