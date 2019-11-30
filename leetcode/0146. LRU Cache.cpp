// 146. LRU Cache

// Design and implement a data structure for Least Recently Used (LRU) cache. 
// It should support the following operations: get and put.
// get(key) - Get the value (will always be positive) of the key if the key 
// exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. 
// When the cache reached its capacity, it should invalidate the least recently 
// used item before inserting a new item.
// The cache is initialized with a positive capacity.
// Follow up:
// Could you do both operations in O(1) time complexity?

// put: O(1), get: O(1)
class LRUCache {
private:
    typedef pair<int, int> Node;
    typedef list<Node>::iterator ref;
    int count, n;
    list<Node> freq;
    unordered_map<int, ref> cache;

public:
    LRUCache(int capacity) {
        count = 0;
        n = capacity;
        freq.clear();
        cache.clear();
    }
    
    int get(int key) {
        auto itr = cache.find(key);
        if (itr != cache.end()) {
            int value = cache[key]->second;
            freq.erase(cache[key]);
            freq.push_front(make_pair(key, value));
            cache[key] = freq.begin();
            return value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            freq.erase(cache[key]);
            freq.push_front(make_pair(key, value));
            cache[key] = freq.begin();
            return;
        }
        count++;
        if (count > n) {
            int evict = freq.back().first;
            freq.erase(cache[evict]);
            cache.erase(evict);
            count--;
        }
        freq.push_front(make_pair(key, value));
        cache[key] = freq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */