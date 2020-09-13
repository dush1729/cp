#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(string s, int zeroone, int onezero) {
		long long c1=0,c2=0;

		int one=0,zero=0;
		for(auto c:s)
		{
			if(c=='1') one++;
			else
			{
				if(one>0) c1+=onezero,one--;
				else zero++;
			}
		}
		c1+=1ll*min(one,zero)*zeroone;

		one=0,zero=0;
		for(auto c:s)
		{
			if(c=='0') zero++;
			else
			{
				if(zero>0) c2+=zeroone,zero--;
				else one++;
			}
		}
		c2+=1ll*min(one,zero)*onezero;
		

		return max(c1,c2);
	}
};

