#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,i,j,d[N];
long long a[N];
int main()
{
    for(i=1;i<N;i++)
        for(j=2*i;j<N;j+=i)
            d[j]+=i;

    for(i=2;i<N;i++) a[i]=a[i-1]+d[i];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
}
