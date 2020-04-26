#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,MIN=-1e5;

int dp[N];

class Solution
{
public:
    // time O(n*logk) | space O(n)
    // we can reduce space to O(k) by keeping track of last k dp elements only
	int constrainedSubsetSum(vector<int>& a, int k)
	{
		int ans=*max_element(a.begin(),a.end());
		int n=a.size();
		a.insert(a.begin(),0);
		k++;

		multiset <int> ms;
		for(int i=1;i<=k;i++)
		{
			dp[i]=max(ms.empty()?MIN:*--ms.end()+a[i],a[i]);
			ms.insert(dp[i]);
			ans=max(ans,dp[i]);
		}

		for(int i=k+1;i<=n;i++)
		{
			ms.erase(ms.find(dp[i-k]));
			dp[i]=max(*--ms.end()+a[i],a[i]);
			ms.insert(dp[i]);
			ans=max(ans,dp[i]);
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