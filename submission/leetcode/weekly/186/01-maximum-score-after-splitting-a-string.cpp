#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20;

int dp[N];

class Solution
{
public:
    // time O(n) | space O(n)
	int maxScore(string a)
	{
		int n=a.size();
		a="$"+a;

		for(int i=1;i<=n;i++)
			dp[i]=dp[i-1]+(a[i]=='1');

		int ans=0;
		for(int i=1;i<n;i++)
		{
			int lt=i-dp[i];
			int rt=dp[n]-dp[i];
			ans=max(ans,lt+rt);
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