class Solution {
public:
	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int ans = INT_MAX;
		for(int m = 0; m * 60 <= targetSeconds; m++) {
			int s = targetSeconds - m * 60;
			if(m > 99 || s > 99) continue;

			string ss = to_string(s);
			string sm = to_string(m);
			if(m == 0) {
				sm = "";
			} else {
				while(ss.size() < 2) ss = "0" + ss;
			}
			string a = sm + ss;

			int cost = 0;
			char prevDig = startAt + '0';
			for(char &c: a) {
				if(c != prevDig) cost += moveCost;
				cost += pushCost;
				prevDig = c;
			}

			ans = min(ans, cost);
		}
		return ans;
	}
};