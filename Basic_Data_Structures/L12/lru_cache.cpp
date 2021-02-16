class LRUCache {
    list<pair<int,int> > l;
    unordered_map<int,list<pair<int,int> >::iterator> m;
    int cap;
public:
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(!m.count(key))
            return -1;
        
        auto p = *(m[key]);
        l.erase(m[key]);
        l.push_back(p);
        m[key] = --l.end();
        
        return p.second;
    }
    
    void put(int key, int value) 
    {
        if(m.count(key))
            l.erase(m[key]);
        
        if(l.size()==cap)
            m.erase(l.begin()->first), l.erase(l.begin());
        
        l.push_back({key,value});
        m[key] = --l.end();
    }
};

