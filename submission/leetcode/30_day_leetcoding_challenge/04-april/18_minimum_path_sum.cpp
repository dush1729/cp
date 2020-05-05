class Solution {
public:
    // time O(n*m) | space O(n*m)
    int minPathSum(vector<vector<int>>& a) {
        vector <vector <int>> dp = a;
        int n=a.size(), m=a[0].size();
        
        for(int j=1;j<m;j++) dp[0][j] = dp[0][j-1] + a[0][j];
        for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + a[i][0];
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
        
        return dp[n-1][m-1];
    }
};