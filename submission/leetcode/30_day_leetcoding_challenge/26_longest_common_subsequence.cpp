
const int N=1e3+20;

int dp[N][N];

class Solution {
public:
    // time O(n*m) | space O(n*m)
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        
        a = "$" + a, b = "$" + b;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};