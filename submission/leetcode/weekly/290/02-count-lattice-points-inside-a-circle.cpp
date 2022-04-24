class Solution {
public:
	int countLatticePoints(vector<vector<int>>& a) {
		int ans = 0;
		for(int x = 0; x <= 200; x++) {
			for(int y = 0; y <= 200; y++) {
				for(auto &v: a) {
					int x1 = v[0], y1 = v[1], r = v[2];
					int d = (x - x1) * (x - x1) + (y - y1) * (y - y1);
					if(d <= r * r) {
						ans++;
						break;
					}
				}
			}
		}
		return ans;
	}
};