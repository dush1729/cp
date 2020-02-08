#include "bits/stdc++.h"
using namespace std;

map <int,int> dp;

class Solution
{
public:
	int numberOfSteps (int num)
	{
		if(num==0) return dp[num]=0;
		if(dp.find(num)!=dp.end()) return dp[num];
		if(num%2==0) return dp[num]=1+numberOfSteps(num/2);
		return dp[num]=1+numberOfSteps(num-1);
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().numberOfSteps(6);
	cout<<ans<<endl;
}
#endif