class MedianFinder {
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty()||num<maxi.top()){
            maxi.push(num);
        }else{
            mini.push(num);
        }
        
        if(maxi.size()+1<mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }
        
        if(mini.size()+1<maxi.size()){
            mini.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size()==mini.size()){
            return ((double)maxi.top()+(double)mini.top())/2;
        }
        else if(maxi.size()>mini.size())
            return maxi.top();
        
        return mini.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */