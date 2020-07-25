#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n;
bool vis[N];


class Solution
{
public:
    int minNumberOperations(vector<int> &a)
    {
        n = a.size();
        a.insert(a.begin(), 0);

        priority_queue <pair <int, int>> pq;
        for(int i = 1; i <= n; i++) pq.push({-a[i], i});

        for(int i = 1; i <= n; i++) vis[i] = false;
        vis[0] = vis[n + 1] = true;

        int segments = 1;
        int pvval = 0, ans = 0;
        while(not pq.empty())
        {
            int val = pq.top().first;
            ans += segments * (pvval - val);
            int x = pq.top().second;
            if(vis[x + 1] and vis[x - 1]) segments--;
            else if(not (vis[x + 1] or vis[x - 1])) segments++;
            vis[x] = true;
            pq.pop();

            while(not pq.empty() and pq.top().first == val)
            {
                int x = pq.top().second;
                if(vis[x + 1] and vis[x - 1]) segments--;
                else if(not (vis[x + 1] or vis[x - 1])) segments++;
                vis[x] = true;
                pq.pop();
            }
            pvval = val;
        }

        return ans;
    }
};