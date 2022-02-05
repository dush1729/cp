class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector <int> l, r;
		int cnt = 0;
		for(int &x: nums) {
			if(x < pivot) l.push_back(x);
			else if(x == pivot) cnt++;
			else r.push_back(x);
		}

		vector <int> ans;
		for(int &x: l) ans.push_back(x);
		while(cnt--) ans.push_back(pivot);
		for(int &x: r) ans.push_back(x);
		return ans;
	}
};