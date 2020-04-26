#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int dp[N];

class Solution
{
public:
    // time O(n) | space O(n)
    // we can reduce space to O(1) by
    // subtracting sum of each sliding window of size n-k from total sum
    // and return max of those
	int maxScore(vector<int>& a, int k)
	{
		int n=a.size();
		dp[0]=a[0];
		for(int i=1;i<n;i++) dp[i]=dp[i-1]+a[i];

		int ans=0;
		for(int l=0;l<=k;l++)
		{
			if(l==0)
			{
				if(k!=n) ans=max(ans,dp[n-1]-dp[n-1-k]);
				else ans=max(ans,dp[n-1]);
			}
			else ans=max(ans,dp[l-1]+(dp[n-1]-dp[n-1-(k-l)]));
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