#include "bits/stdc++.h"
using namespace std;

const int M = 4e3 + 20;

class Solution
{
public:
    int longestAwesome(string a)
    {
        int n = a.size();
        vector <int> dp(M, n);
        dp[0] = -1;

        int ans = 0, mask = 0;
        for(int i = 0; i < n; i++)
        {
            mask ^= (1 << (a[i] - '0'));
            ans = max(ans, i - dp[mask]);
            for(int p = 1; p <= 1024; p *= 2)
                ans = max(ans, i - dp[mask ^ p]);
            dp[mask] = min(dp[mask], i);
        }

        return ans;
    }
};