class MyHashSet {
    vector<vector<int>>p;
public:
    MyHashSet() {
        p.resize(100);
    }
    
    void add(int key) {
        int hash=key%100;
        if(!contains(key))
            p[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash=key%100;
        for(auto it=p[hash].begin();it!=p[hash].end();it++){
            if(*it==key){
                p[hash].erase(it);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int hash=key%100;
        for(auto it:p[hash]){
            if(it==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */