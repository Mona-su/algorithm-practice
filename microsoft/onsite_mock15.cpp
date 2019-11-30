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

// put: O(1), get: O(n)
class LRUCache {
private:
    int count, n;
    list<int> freq;
    unordered_map<int, int> cache;
    
    void access(int key) {
        for (auto itr = freq.begin(); itr != freq.end(); itr++) {
            if (*itr == key) {
                freq.erase(itr);
                freq.push_back(key);
                break;
            }
        }
    }
public:
    LRUCache(int capacity) {
        count = 0;
        n = capacity;
    }
    
    int get(int key) {
        auto itr = cache.find(key);
        if (itr != cache.end()) {
            access(key);
            return itr->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            access(key);
            return;
        }
        count++;
        if (count > n) {
            int evict = *freq.begin();
            freq.erase(freq.begin());
            cache.erase(evict);
            count--;
        }
        freq.push_back(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */