#include "solution.hpp"
using namespace std;

const int N=2e5+20;

int dp[N][2];

class Solution {
	public:
	int solve(string a) {
		int n=a.size();
		if(n==1) return 0;

		a+=a;
		a="$"+a;

		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
			if(i%2==0 and a[i]=='0') dp[i][0]++;
			else if(i%2==1 and a[i]=='1') dp[i][0]++;
			else if(i%2==0 and a[i]=='1') dp[i][1]++;
			else if(i%2==1 and a[i]=='0') dp[i][1]++;
		}

		int ans=min(dp[n][0],dp[n][1]);
		for(int i=n+1;i<=2*n;i++)
		{
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
			if(i%2==0 and a[i]=='0') dp[i][0]++;
			else if(i%2==1 and a[i]=='1') dp[i][0]++;
			else if(i%2==0 and a[i]=='1') dp[i][1]++;
			else if(i%2==1 and a[i]=='0') dp[i][1]++;

			if((i-n)%2==0 and a[i-n]=='0') dp[i][0]--;
			else if((i-n)%2==1 and a[i-n]=='1') dp[i][0]--;
			else if((i-n)%2==0 and a[i-n]=='1') dp[i][1]--;
			else if((i-n)%2==1 and a[i-n]=='0') dp[i][1]--;

			ans=min(ans,dp[i][0]);
			ans=min(ans,dp[i][1]);
		}
		return ans;
	}
};
