#pragma once
class LRUCache {
public:
    LRUCache(int capacity)
        :_capacity(capacity)
    {
    }

    int get(int key) {
        auto it = _hashMap.find(key);
        if (it != _hashMap.end()) {
            _list.splice(_list.begin(), _list, it->second);
            return it->second->second;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = _hashMap.find(key);
        if (it != _hashMap.end()) {
            it->second->second = value;
            _list.splice(_list.begin(), _list, it->second);
        }
        else {
            _list.push_front(make_pair(key, value));
            _hashMap[key] = _list.begin();
        }
        if (_capacity < _hashMap.size()) {
            auto it = _list.back();
            _hashMap.erase(it.first);
            _list.pop_back();
        }
    }

private:
    int _capacity;
    typedef list<pair<int, int>>::iterator Iterator;
    unordered_map<int, Iterator> _hashMap;
    list<pair<int, int>> _list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
