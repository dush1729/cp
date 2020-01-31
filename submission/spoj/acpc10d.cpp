//Purple before 1st August 2k17
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
long long t,n,i,a[N][3],dp[N][3];
int main()
{
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;
        for(i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);

        dp[1][0]=a[1][1]+1;
        dp[1][1]=a[1][1];
        dp[1][2]=a[1][2]+dp[1][1];

        for(i=2;i<=n;i++)
        {
            dp[i][0]=a[i][0]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=a[i][1]+min({dp[i][0],dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            dp[i][2]=a[i][2]+min({dp[i][1],dp[i-1][1],dp[i-1][2]});
        }

        printf("%lld. %lld\n",++t,dp[n][1]);
    }
}
