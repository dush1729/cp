class Solution {
public:
	vector<int> intersection(vector<vector<int>>& a) {
		map <int, int> m;
		for(auto &v: a)
			for(auto &x: v) m[x]++;

		vector <int> v;
		for(auto &[x, f]: m)
			if(f == a.size()) v.push_back(x);
		return v;
	}
};