#define F first
#define S second

class LFUCache {
private: 
    map<int,pair<int,int>> mapKeyValFreq;
    map<int,list<int>> mapFreqList;
    map<int,list<int>::iterator> mapKeyIter;
    int currSize;
    int cap;
    int minFreq;
public:
    LFUCache(int capacity) {
        cap = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreq(int key)
    {
        int currFreq = mapKeyValFreq[key].S;
        mapFreqList[currFreq].erase(mapKeyIter[key]);
        if(mapFreqList[minFreq].size()==0)
            minFreq++;
        currFreq++;
        mapKeyValFreq[key].S = currFreq;
        mapFreqList[currFreq].push_front(key);
        mapKeyIter[key] = mapFreqList[currFreq].begin();    
    }
    
    int get(int key) 
    {
        if(mapKeyValFreq.find(key)!=mapKeyValFreq.end())
        {
            updateFreq(key);
            return mapKeyValFreq[key].F;
        }
        return -1;
    }
    
    //remove element with minFreq (if more than one element then LRU policy)
    void remove()
    {
        int key = mapFreqList[minFreq].back();
        mapFreqList[minFreq].pop_back();
        mapKeyValFreq.erase(key);
        mapKeyIter.erase(key);
        currSize--;
    }
    
    void put(int key, int value) 
    {
        if(cap==0)
            return;
        int val = get(key);
        if(val!=-1)
        {
            mapKeyValFreq[key].F = value;
            return;
        }
        if(currSize>=cap)
        {
            remove(); 
        }
        mapKeyValFreq[key] = {value,1};
        mapFreqList[1].push_front(key);
        mapKeyIter[key] = mapFreqList[1].begin();
        minFreq = 1;
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
