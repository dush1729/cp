#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
        // O(N) time | O(1) space
        // O(NLOGN) time | O(1) space
		int ans=INT_MIN,sum=0;
		for(auto i:nums)
		{
			sum+=i;
			if(sum>ans) ans=sum;
			if(sum<0) sum=0;
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