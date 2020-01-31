#include<bits/stdc++.h>
using namespace std;
const int mod=10000007;
int z,t,n,i,j,x,f[32];
long long ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<32;i++) f[i]=0;
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(j=0;j<32;j++)
            {
                f[j]+=x%2;
                x/=2;
            }
        }
        for(i=0;i<32;i++) ans=(ans+2*f[i]*(n-f[i]))%mod;
        printf("Case %d: %lld\n",++z,ans);
    }
    return 0;
}
