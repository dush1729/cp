#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20,MAX=1e6+1;
long long dp[N],i,ans,idx;
long long f(long long x)
{
    if(x>=N)
    {
        if(x&1) return 1+f(x*3+1);
        return 1+f(x>>1);
    }
    if(dp[x]!=-1) return dp[x];
    if(x&1) return dp[x]=1+f(x*3+1);
    return dp[x]=1+f(x>>1);
}
int main()
{
    for(i=0;i<N;i++) dp[i]=-1;
    dp[1]=0;

    for(i=2;i<MAX;i++)
    {
        if(ans<f(i))
        {
            ans=f(i);
            idx=i;
        }
    }
    cout<<idx;
}
