class LRUCache {
    int N;
    list<int> pages;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) : N(capacity) {
        
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            pages.erase(cache[key].second);
            pages.push_front(key);
            cache[key].second = pages.begin();
            return cache[key].first;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            pages.erase(cache[key].second);
        } else {
            if (pages.size() == N) {
                int lru = pages.back();
                cache.erase(lru);
                pages.pop_back();
            }
        }
        
        pages.push_front(key);
        cache[key] = {value, pages.begin()};
    }
};
