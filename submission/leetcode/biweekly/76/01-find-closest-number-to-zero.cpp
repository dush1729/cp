class Solution {
public:
	int findClosestNumber(vector<int>& nums) {
		int mn = INT_MAX, res;
		for(int &x: nums) {
			if(abs(x) < mn) {
				mn = abs(x);
				res = x;
			} else if(abs(x) == mn) {
				res = max(res, x);
			}
		}
		return res;
	}
};
