//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string topo(vector<int> adj[], int k)
    {
        queue<int> q;
        vector<int> in(k, 0);
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            for(auto it : adj[i])
            {
                in[it]++;
            }
        }
        
        for(int i = 0; i < k; i++)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto it : adj[f])
            {
                in[it]--;
                if(in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        string s = "";
        for(auto it : ans)
        {
            s += char(it + 'a');
        }
        return s;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0; i < N - 1; i++)
        {
            string a = dict[i], b = dict[i + 1];
            int len = min(a.length(), b.length());
            for(int j = 0; j < len; j++)
            {
                if(a[j] != b[j])
                {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }
        return topo(adj, K);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends