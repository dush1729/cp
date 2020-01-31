#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int t,n,i,x,s;
map <int,int> m;
long long ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        s=ans=0;
        m.clear();

        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            s+=x;
            ans+=m[s]+(s==0);
            m[s]++;
        }

        printf("%lld\n",ans);
    }
}
