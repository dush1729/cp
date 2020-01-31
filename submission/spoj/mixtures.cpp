#include<bits/stdc++.h>
using namespace std;
const int N=120,mod=100;
int n,i,j,a[N],smoke[N][N];
int ans(int l,int r)
{
    if(smoke[l][r]!=-1) return smoke[l][r];

    if(l>=r) return smoke[l][r]=0;

    int i,s=INT_MAX,ls[N],rs[N];

    ls[l-1]=rs[r+1]=0;
    for(i=l;i<=r;i++) ls[i]=(ls[i-1]+a[i])%mod;
    for(i=r;i>=l;i--) rs[i]=(rs[i+1]+a[i])%mod;

    for(i=l;i<r;i++)
        s=min(s,ans(l,i)+ans(i+1,r)+ls[i]*rs[i+1]);

    return smoke[l][r]=s;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        for(i=0;i<=n;i++) for(j=0;j<=n;j++) smoke[i][j]=-1;

        printf("%d\n",ans(1,n));
    }
}
