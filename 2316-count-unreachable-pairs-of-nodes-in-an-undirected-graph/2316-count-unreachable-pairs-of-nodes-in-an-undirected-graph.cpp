class Solution {
public:
    int findParent(int i, vector<int>& parent)
    {
        if(parent[i] != i)
        {
            parent[i] = findParent(parent[i], parent);
        }
        return parent[i];
    }

    void unionSet(int i, int j, vector<int>& parent, vector<int>& rank)
    {
        int iPar = findParent(i, parent), jPar = findParent(j, parent);
        if(iPar == jPar)
        {
            return;
        }
        else if(rank[iPar] < rank[jPar])
        {
            parent[iPar] = jPar; 
        }
        else if(rank[iPar] > rank[jPar])
        {
            parent[jPar] = iPar;
        }
        else
        {
            parent[jPar] = iPar;
            rank[iPar]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for(auto it : edges)
        {
            unionSet(it[0], it[1], parent, rank);
        }

        map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[findParent(i, parent)]++;
        }
        long long int pairs = 0, count = n;
        for(auto it : m)
        {
            long long int size = it.second;
            pairs += size * (count - size);
            count -= size;
        }
        return pairs;
    }
};