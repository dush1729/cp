#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	int minStartValue(vector<int>& nums)
	{
		int sum=0,ans=1;
		for(auto i:nums)
		{
			sum+=i;
			if(sum<0) ans=max(ans,-sum+1);
		}
		return ans;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif