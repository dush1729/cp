class Solution {
public:
    // time O(n) | space O(1)
    bool canJump(vector<int>& a) {
        int n = a.size(), end = 0;
        for(int i = 0; i <= min(n - 1, end); i++) {
            end = max(end, i + a[i]);
        }
        return end >= n - 1;
    }

    // time O(n^2) | space O(n) 
    bool canJump(vector<int>& a) {
        int n = a.size();
        vector <int> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(j + a[j] >= i and dp[j] == true) {
                    dp[i] = true;
                }
            }
        }
        return dp.back();
    }
};