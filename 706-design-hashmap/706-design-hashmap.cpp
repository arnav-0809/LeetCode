class MyHashMap {
    vector<vector<pair<int,int>>>v;
    int c=991;
public:
    MyHashMap() {
        v.resize(991);
    }
    
    void put(int key, int value) {
        int hash=key%c;
        int flag=0;
        for(int i=0;i<v[hash].size();i++){
            if(v[hash][i].first==key){
                flag=1;
                v[hash][i].second=value;
                break;
            }
        }
        if(flag==0){
            v[hash].push_back({key,value});
        }
    }
    
    int get(int key) {
        int hash=key%c;
        for(int i=0;i<v[hash].size();i++){
            if(v[hash][i].first==key){
                return v[hash][i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash=key%c;
        for(int i=0;i<v[hash].size();i++){
            if(v[hash][i].first==key){
                v[hash][i].second=-1;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */