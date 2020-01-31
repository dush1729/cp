#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int t,n,i,a[N],s,ans;
long long f;
unordered_map <int,int> m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        ans=s=a[1];
        for(i=2;i<=n;i++)
        {
            s+=a[i];
            ans=max(ans,s);
            s=max(0,s);
        }

        f=s=0;
        m.clear();
        m[0]++;
        for(i=1;i<=n;i++)
        {
            s+=a[i];
            f+=m[s-ans];
            m[s]++;
        }

        printf("%d %lld\n",ans,f);
    }
}
