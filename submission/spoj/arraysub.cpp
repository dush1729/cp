#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define lld I64d
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false)
#define rep(i,a,n) for(__typeof(n) i=a;i<=n;i++)
int a[1000000];
multiset <int> b;
multiset <int>::iterator it;
int main()
{
    int n,k,i;
    sc("%d",&n);
    for(i=0;i<n;i++) sc("%d",&a[i]);
    scanf("%d",&k);
    for(i=0;i<k;i++) b.insert(a[i]);
    it=b.end();
    it--;
    pr("%d ",*it);
    for(i=1;i<=n-k;i++)
    {
        b.erase(b.find(a[i-1]));
        b.insert(a[i+k-1]);
        it=b.end();
        it--;
        pr("%d ",*it);
    }
    pr("\n");
    return 0;
}
