class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& a) {
		int n = a.size();
		vector <int> dp = {0};
		for(int &x: a) dp.push_back(dp.back() + x);

		int mx = 0;
		vector <int> ans;
		for(int i = 0; i <= n; i++) {
			int l = i - (dp[i] - dp[0]), r = dp[n] - dp[i];
			//cout << l << " " << r << endl;
			if(mx < l + r) {
				mx = l + r;
				ans.clear();
				ans.push_back(i);
			} else if(mx == l + r) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};