class Solution {
public:
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {
		long long ans = 0;
		for(long long pen = 0; pen * cost1 <= total; pen++) {
			long long x = total - pen * cost1;
			ans += x / cost2 + 1;
		}
		return ans;
	}
};