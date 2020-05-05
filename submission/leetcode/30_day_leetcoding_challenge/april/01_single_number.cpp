#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int x=0;
		for(auto i:nums) x^=i;
		return x;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif