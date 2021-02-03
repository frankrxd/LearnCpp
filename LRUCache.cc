
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto x = _mycache.find(key);
        if(x == _mycache.end())
            return -1;
        else {
            _lruList.splice(_lruList.begin(),_lruList,x->second);
            return x->second->second;
        }
    }

    void put(int key, int value) {
        auto ret = _mycache.find(key);
        if(ret == _mycache.end())
        {
            if(_lruList.size() == _capacity)
            {
                //执行LRU淘汰策略
                _mycache.erase((--_lruList.end())->first);
                _lruList.pop_back();
            }

            //更新cache
            _lruList.push_front(make_pair(key,value));
            _mycache[key] = _lruList.begin();
        }
        else{
            ret->second->second = value;
            _lruList.splice(_lruList.begin(),_lruList,ret->second);
        }

    }

private:
    size_t _capacity;
    list<pair<int,int>> _lruList;
    unordered_map<int,list<pair<int,int>>::iterator> _mycache;
};

