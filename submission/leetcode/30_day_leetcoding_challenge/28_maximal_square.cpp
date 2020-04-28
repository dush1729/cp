
const int N = 1e3 + 20;
int dp[N][N];

class Solution {
public:
	// time O(n*m) | space O(n*m)
	int maximalSquare(vector<vector<char>>& a) {
		if(a.empty()) return 0;
		int n = a.size(), m = a[0].size();
		int len = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(i == 0 or j == 0 or a[i][j] == '0') {
					dp[i][j] = a[i][j] - '0';
				} else {
					dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
				}
				len = max(len, dp[i][j]);
			}
		}
		return len * len;
	}
};