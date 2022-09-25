class MyHashSet {
public:
    
    //pair.first == 0 - empty since start
    //pair.first == 1 - used
    //pair.first == 2 - empty due to remove
    static const int data_max = 10000;
    pair<int,int> data[data_max];

    MyHashSet() {
    }
    
    void add(int key) {
        int hash = key % data_max;
        for(int i = hash; i < data_max;++i)
        {
            if(data[i].first == 0 || data[i].first == 2)
            {
                data[i] = pair<int,int>(1,key);
                break;
            }
        }
    }
    
    void remove(int key) {
        int hash = key % data_max;
        for(int i = hash; i < data_max;++i)
        {
            if(data[i].second == key)
            {
                data[i] = pair<int,int>(2,0);
            }
            
            if(data[i].first == 0)
                break;
        }
        
    }
    
    bool contains(int key) {
        int hash = key % data_max;
        for(int i = hash; i < data_max;++i)
        {
            if(data[i].first == 1 && data[i].second == key)
                return true;
            
            if(data[i].first == 0)
                break;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */