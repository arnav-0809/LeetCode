class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>m;
        int n=fruits.size();
        queue<int>q;
        int maxi=0;
        for(int i=0;i<n;i++){
            m[fruits[i]]++;
            q.push(fruits[i]);
            if(!q.empty() && m.size()>2){
                m[q.front()]--;
                if(m[q.front()]==0){
                    m.erase(q.front());
                }
                q.pop();
            }

            maxi = max(maxi,(int)q.size());
        }
        return maxi;
    }
};