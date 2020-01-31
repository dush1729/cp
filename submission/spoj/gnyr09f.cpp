#include<bits/stdc++.h>
using namespace std;
const int N=120;
int T,t,n,k,dp[N][N][2];
bool c[N][N];
int f(int n,int k)
{
    if(c[n][k]) return dp[n][k][0]+dp[n][k][1];
    c[n][k]=true;
    if(n==1)
    {
        if(k==0) dp[n][k][0]=dp[n][k][1]=1;
        return dp[n][k][0]+dp[n][k][1];
    }
    dp[n][k][0]=f(n-1,k);
    dp[n][k][1]=dp[n-1][k][0];
    if(k>0)
    {
        f(n-1,k-1);
        dp[n][k][1]+=dp[n-1][k-1][1];
    }
    return dp[n][k][0]+dp[n][k][1];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&t,&n,&k);
        printf("%d %d\n",t,f(n,k));
    }
}
