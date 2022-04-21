class MyHashSet {
    set<int>p;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        p.insert(key);
    }
    
    void remove(int key) {
        for(auto it=p.begin();it!=p.end();it++){
            if(*it==key){
                p.erase(it);
                break;
            }
        }
    }
    
    bool contains(int key) {
        for(auto it:p){
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