class Solution {
public:
	int mostFrequent(vector<int>& a, int key) {
		int n = a.size(), ans = 0, mx = 0;
		map <int, int> f;
		for(int i = 0; i < n - 1; i++) {
			if(a[i] == key) f[a[i + 1]]++;
		}

		for(auto &[x, y]: f)
			if(y > mx) mx = y, ans = x;
		return ans;
	}
};