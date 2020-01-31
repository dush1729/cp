#include<stdio.h>
unsigned long long max(unsigned long long a,unsigned long long b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        unsigned long long N,i,a[1000],dp[1000];
        scanf("%llu",&N);
        for(i=0;i<N;i++) scanf("%llu",&a[i]);
        if(N==0) printf("Case %d: 0\n",t);
        else if(N==1) printf("Case %d: %llu\n",t,a[0]);
        else if(N==2) printf("Case %d: %llu\n",t,max(a[0],a[1]));
        else
        {
            dp[0]=a[0];
            if(a[0]<a[1]) dp[1]=a[1];
            else dp[1]=a[0];
            for(i=2;i<N;i++) dp[i]=max(a[i]+dp[i-2],dp[i-1]);
            printf("Case %d: %llu\n",t,dp[N-1]);
        }

    }
    return 0;
}
