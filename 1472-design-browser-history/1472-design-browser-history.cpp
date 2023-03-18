class BrowserHistory {
    vector<string> his;
    int curr, last;
public:
    BrowserHistory(string homepage) {
        curr = 0;
        last = 0;
        his.push_back(homepage);
    }
    
    void visit(string url) {
        curr += 1;
        if(his.size() > curr)
        {
            his[curr] = url;
        }
        else
        {
            his.push_back(url);
        }
        last = curr;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return his[curr];
    }
    
    string forward(int steps) {
        curr = min(last, curr + steps);
        return his[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */