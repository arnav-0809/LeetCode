class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = capital.size();
        for(int i = 0; i < n; i++)
        {
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end());

        priority_queue<int> p;
        int c = 0;
        while(k--)
        {
            while(c < n && v[c].first <= w)
            {
                p.push(v[c].second);
                c++;
            }

            if(p.empty())
            {
                break;
            }

            w += p.top();
            p.pop();
        }

        return w;
    }
};