#include<bits/stdc++.h>
using namespace std;
const int N=31;
int n,i,x,a[N];
long long ans;
int main()
{
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&x);
        for(i=0;i<N;i++) a[i]+=x&1, x>>=1;
    }

    for(i=0;i<N;i++) ans+=1LL*(1<<i)*a[i]*(n-a[i]);
    printf("%lld",ans);
}
