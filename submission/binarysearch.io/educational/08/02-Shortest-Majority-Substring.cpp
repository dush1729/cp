#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(string a) {
		int n=a.size();
		for(int i=1;i<n;i++)
			if(a[i]==a[i-1]) return 2;
		for(int i=2;i<n;i++)
			if(a[i]==a[i-2]) return 3;
		return -1;
	}
};
