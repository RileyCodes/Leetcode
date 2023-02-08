class LRUCache {
public:

    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    list<pair<int, int>> m_cache;
    int m_capacity;
    LRUCache(int capacity) : m_capacity(capacity){}
    
    int get(int key) {
        auto it = m_map.find(key);
        if(it == m_map.end())
            return -1;
        m_cache.splice(m_cache.begin(), m_cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_map.find(key);
        if(it != m_map.end())
        {
            m_cache.splice(m_cache.begin(), m_cache, it->second);
            it->second->second = value;
            return;
        }
        if(m_capacity <= 0)
        {
            m_map.erase(m_cache.back().first);
            m_cache.pop_back();
            ++m_capacity;
        }

        m_cache.emplace_front(key,value);
        m_map[key] = m_cache.begin();
        --m_capacity;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */