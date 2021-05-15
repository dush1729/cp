class Solution {
public:
	vector<int> memLeak(int memory1, int memory2) {
		for(int i = 1; ; i++) {
			if(memory1 >= memory2) {
				if(i <= memory1) {
					memory1 -= i;
				} else {
					return {i, memory1, memory2};
				}
			} else {
				if(i <= memory2) {
					memory2 -= i;
				} else {
					return {i, memory1, memory2};
				}
			}
		}
		return {};
	}
};