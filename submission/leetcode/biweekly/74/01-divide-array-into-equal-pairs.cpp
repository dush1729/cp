class Solution {
public:
	bool divideArray(vector<int>& a) {
		map <int, int> m;
		for(int &x: a) m[x]++;

		for(auto &[_, f]: m)
			if(f % 2) return false;
		return true;
	}
};