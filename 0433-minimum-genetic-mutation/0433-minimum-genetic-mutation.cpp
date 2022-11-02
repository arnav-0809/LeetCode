class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        set<string>s;
        q.push(start);
        s.insert(start);
        set<string>b;
        
        for(int i = 0; i < bank.size(); i++)
        {
            b.insert(bank[i]);
        }
        
        int steps = 0;
        while(!q.empty()){
            
           int num = q.size();
            
            for (int j = 0; j < num; j++) {
                string str = q.front();
                q.pop();

                if (str == end) {
                    return steps;
                }
                
                for (char c: "ACGT") {
                    for (int i = 0; i < str.size(); i++) {
                        string dup = str;
                        dup[i] = c;
                        if (!s.count(dup) && b.count(dup)) {
                            q.push(dup);
                            s.insert(dup);
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};