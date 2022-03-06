class Solution {
public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		vector <array <int, 3>> a;
		for(int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			string s = to_string(x);
			for(char &c: s) c = '0' + mapping[c - '0'];
			a.push_back({stoi(s), x, i});
		}

		sort(a.begin(), a.end(), [](const auto &u, const auto &v) {
			if(u[0] != v[0]) return u[0] < v[0];
			return u[2] < v[2];
		});

		vector <int> ans;
		for(auto &[_, x, i]: a) ans.push_back(x);
		return ans;
	}
};