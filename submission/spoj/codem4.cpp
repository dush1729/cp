#include<bits/stdc++.h>
using namespace std;
const int N=32;
int t,n,i,j,a[N],dp[N][N],dp2[N][N][2];
int f1(int l,int r)
{

    if(dp[l][r]!=-1) return dp[l][r];
    if(l>r) return dp[l][r]=0;
    return dp[l][r]=max({a[l]+f1(l+2,r),a[l]+f1(l+1,r-1),
                a[r]+f1(l,r-2),a[r]+f1(l+1,r-1)});
}
int f2(int l,int r,bool turn)
{
    if(dp2[l][r][turn]!=-1) return dp2[l][r][turn];
    if(l>r) return dp2[l][r][turn]=0;
    if(turn)
    {
        return dp2[l][r][turn]=max({a[l]+f2(l+1,r,!turn),
                                    a[r]+f2(l,r-1,!turn)});
    }
    return dp2[l][r][turn]=min({f2(l+1,r,!turn),
                                f2(l,r-1,!turn)});
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j]=dp2[i][j][0]=dp2[i][j][1]=-1;
        printf("%d ",f1(1,n));
        printf("%d\n",f2(1,n,true));
    }
}
