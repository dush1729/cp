#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20,MAX=1e7+20;
int t,n,i,a[N],BIT[MAX],v;
long long ans;
void update(int x,int delta)
{
    for(;x<MAX;x+=x&-x) BIT[x]+=delta;
}
int query(int x)
{
    int sum=0;
    for(;x>0;x-=x&-x) sum+=BIT[x];
    return sum;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<MAX;i++) BIT[i]=0;
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        for(i=n;i>=1;i--)
        {
            v=query(a[i]);
            ans+=v;
            update(a[i],v-query(a[i]-1)+1);
        }
        printf("%lld\n",ans);
    }
}
