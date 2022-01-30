class Solution {
public:
	int findFinalValue(vector<int>& a, int x) {
		sort(a.begin(), a.end());
		while(1729) {
			if(binary_search(a.begin(), a.end(), x)) {
				x *= 2;
			} else {
				break;
			}
		};
		return x;
	}
};