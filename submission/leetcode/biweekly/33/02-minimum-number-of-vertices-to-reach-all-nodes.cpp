#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n;
vector <int> adj[N];

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int nn, vector<vector<int>> &edges)
    {
        n = nn;
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        for(auto v : edges) adj[v[1]].push_back(v[0]);

        vector <int> ans;

        for(int i = 0; i < n; i++)
            if(adj[i].empty()) ans.push_back(i);
        return ans;
    }
};
/*
time O(n)
space O(n)
*/