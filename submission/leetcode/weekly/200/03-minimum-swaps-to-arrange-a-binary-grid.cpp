#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector <int> a;
        for(auto v : grid)
        {
            int zero = 0;
            for(int i = n - 1; i >= 0 and v[i] == 0; i--, zero++);
            a.push_back(zero);
        }

        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int req = n - 1 - i;
            if(a[i] >= req) continue;

            int idx = i + 1;
            while(idx < n and a[idx] < req) idx++;
            if(idx == n) return -1;

            while(idx > i)
            {
                swap(a[idx], a[idx - 1]);
                idx--;
                ans++;
            }
        }
        return ans;
    }
};