class Solution {
public:
	vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
		vector a(101, vector (0, 0));
		for(auto &v: rectangles) {
			a[v[1]].push_back(v[0]);
		}
		for(int i = 0; i <= 100; i++) {
			sort(a[i].begin(), a[i].end());
		}

		vector ans(0, 0);
		for(auto &v: points) {
			int res = 0;
			for(int y = v[1]; y <= 100; y++) {
				res += a[y].end() - lower_bound(a[y].begin(), a[y].end(), v[0]);
			}
			ans.push_back(res);
		}
		return ans;
	}
};