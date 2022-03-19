class Solution {
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int n = floor.size();
		vector dp(numCarpets + 1, vector (n + 1, 0));
		for(int j = 1; j <= n; j++) {
			dp[0][j] = dp[0][j - 1];
			if(floor[j - 1] == '1') dp[0][j]++;
		}
		for(int i = 1; i <= numCarpets; i++) {
			dp[i] = dp[i - 1];
			for(int j = 1; j <= n; j++) {
				if(j >= carpetLen) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - carpetLen]);
				} else {
					dp[i][j] = 0;
				}
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + (floor[j - 1] == '1'));
			}
		}
		return dp[numCarpets][n];
	}
};