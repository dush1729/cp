#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20,MAX=1e6+20;
int t,n,i,a[N];
long long BIT[MAX],ans;
void update(int x,int delta)
{
    for(;x<MAX;x+=x&-x) BIT[x]+=delta;
}
long long query(int x)
{
    long long sum=0;
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
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0) continue;
            ans+=query(a[i]-1);
            update(a[i],a[i]);
        }
        printf("%lld\n",ans);
    }
}
