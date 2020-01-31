#include<bits/stdc++.h>
using namespace std;
const int N=120,MAX=1<<25;
int t,n,k,i,j,a[N],dp[N];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=k;i++) scanf("%d",&a[i]);

        for(i=0;i<=k;i++) dp[i]=MAX;
        dp[0]=0;

        for(i=1;i<=k;i++)
        {
            if(a[i]==-1) continue;
            for(j=i;j<=k;j++)
                dp[j]=min(dp[j],dp[j-i]+a[i]);
        }

        if(dp[k]==MAX) dp[k]=-1;
        printf("%d\n",dp[k]);
    }
}
