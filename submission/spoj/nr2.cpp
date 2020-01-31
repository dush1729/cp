#include<bits/stdc++.h>
using namespace std;
int n,i;
long long x,ans1,ans2=LLONG_MAX;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        ans1|=x;
        ans2&=x;
    }
    printf("%lld",ans1^ans2);
}
