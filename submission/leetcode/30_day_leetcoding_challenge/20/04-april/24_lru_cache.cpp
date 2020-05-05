class LRUCache {
public:
    
    int limit;
    list <int> a; // 1 2 3 -> 3 2 1
    map <int, pair <int, list <int>::iterator>> cache;
    
    LRUCache(int capacity) {
        limit = capacity;
        a.clear();
        cache.clear();
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        moveToFront(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) moveToFront(it);
        else {
            if(cache.size() == limit) {
                cache.erase(a.back());
                a.pop_back();
            }
            a.push_front(key);
        }
        cache[key] = {value, a.begin()};
    }
    
    // O(n)
    void moveToFront(map <int, pair <int, list <int>::iterator>>::iterator it) {
        int key = it->first;
        a.erase(it->second.second); // O(n)
        a.push_front(key);
        it->second.second = a.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */