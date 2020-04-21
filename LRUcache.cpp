class LRUCache {
private:
    list<int> dq;
    int sz;
    unordered_map<int,list<int>::iterator> mp;
    unordered_map<int,int> keyVal;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(keyVal.find(key)!=keyVal.end())
        {
            dq.erase(mp[key]);
            dq.push_front(key);
            mp[key] = dq.begin();
            return keyVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyVal.find(key)==keyVal.end()) // key not present
        {
            if(dq.size()==sz)
            {
                int last = dq.back();
                dq.pop_back();
                keyVal.erase(last);
            }
        }
        else
        {
            dq.erase(mp[key]);
        }
        dq.push_front(key);
        keyVal[key] = value;
        mp[key] = dq.begin();
     }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
