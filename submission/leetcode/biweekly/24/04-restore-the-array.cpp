#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;

class Solution
{
public:
	int numberOfArrays(string a, int k)
	{
		int n=a.size();
		vector <int> dp(n+1,0);
		a="$"+a;
		dp[0]=1;

		for(int i=1;i<=n;i++)
		{
			long long val=0,p=1;
			for(int j=i;j>=max(i-11,1);j--,p*=10)
			{
				val+=(a[j]-'0')*p;
				if(a[j]!='0' and val<=k) dp[i]+=dp[j-1],dp[i]%=MOD;
				//cout<<i<<" "<<j<<" "<<s<<" "<<(a[j]!='0' and val<=k)<<endl;
			}
		}

		return dp.back();
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().numberOfArrays("600342244431311113256628376226052681059918526204",703);
	cout<<ans<<endl;
}
#endif