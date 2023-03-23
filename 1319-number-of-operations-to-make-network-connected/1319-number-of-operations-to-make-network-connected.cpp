class Solution {
public:
    void unionSet(int i, int j, vector<int>& parent, vector<int>& rank)
    {
        int iPar = findParent(i, parent), jPar = findParent(j, parent);
        if(rank[iPar] > rank[jPar])
        {
            parent[jPar] = iPar;
        }
        else if(rank[jPar] < rank[iPar])
        {
            parent[iPar] = jPar;
        }
        else
        {
            parent[iPar] = jPar;
            rank[jPar]++;
        }
    }

    int findParent(int i, vector<int>& parent)
    {
        if(parent[i] != i)
        {
            parent[i] = findParent(parent[i], parent);
        }
        return parent[i];
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size(), ans = n;
        if(n > m + 1)
        {
            return -1;
        }

        vector<int> rank(n, 0), parent(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for(auto it : connections)
        {
            if(findParent(it[0], parent) != findParent(it[1], parent))
            {
                ans -= 1;
                unionSet(it[0], it[1], parent, rank);
            }
        }
        return ans - 1;
    }
};