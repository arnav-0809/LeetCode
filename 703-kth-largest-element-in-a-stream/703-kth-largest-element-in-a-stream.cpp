class KthLargest {
    int l;
    priority_queue<int,vector<int>,greater<int>>p;
public:
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(auto i:nums){
            p.push(i);
        }
        
        while(p.size()>l){
            p.pop();
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>l){
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */