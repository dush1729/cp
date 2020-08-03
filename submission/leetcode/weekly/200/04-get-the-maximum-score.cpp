#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20, MOD = 1e9 + 7;

long long dp[2][N];

class Solution
{
public:
    int maxSum(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        long long ans = 0;
        vector <pair <int, int>> common = {{0, 0}};
        for(int i = 0; i < n; i++)
        {
            auto j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if(j == m or b[j] != a[i]) continue;
            common.push_back({i + 1, j + 1});
        }
        common.push_back({n + 1, m + 1});

        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);
        for(int i = 1; i <= n; i++) dp[0][i] = dp[0][i - 1] + a[i];
        for(int i = 1; i <= m; i++) dp[1][i] = dp[1][i - 1] + b[i];
        dp[0][n + 1] = dp[0][n];
        dp[1][m + 1] = dp[1][m];

        for(int i = 1; i < common.size(); i++)
        {
            ans += max(dp[0][common[i].first] - dp[0][common[i - 1].first]
                       , dp[1][common[i].second] - dp[1][common[i - 1].second]);
        }

        return ans % MOD;
    }
};