#include<bits/stdc++.h>
using namespace std;
const int N=120;
int n,i,j,k,a[N];
long long ans;
unordered_map <int,int> m;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++) m[a[i]*a[j]+a[k]]++;

    for(i=0;i<n;i++)
    {
        if(!a[i]) continue;
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                ans+=m[(a[j]+a[k])*a[i]];
    }

    printf("%lld",ans);
}
