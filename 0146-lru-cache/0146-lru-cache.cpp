class LRUCache {
public:
    int n;
    vector<pair<int, int>> vec; //
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == key) {
                pair<int, int> temp = vec[i];
                vec.erase(vec.begin() + i);
                vec.push_back(temp);
                return temp.second  ;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for(int i = 0 ; i< vec.size() ; i++){
            if(vec[i].first == key){
                vec[i].second = value;
                 pair<int, int> temp = vec[i];
                vec.erase(vec.begin() + i);
                vec.push_back(temp);

                return;
            }
        }
        if(vec.size() < n){
          
            vec.push_back({key , value});
        }else {
            vec.erase(vec.begin());
            vec.push_back({key , value});
        }
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */