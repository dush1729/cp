#include<bits/stdc++.h>
using namespace std;
bool qf=false;      //fast io enabled/disabled

#define input       freopen("in.txt","r",stdin);
#define output      freopen("out.txt","w",stdout);
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);qf=true;

#define sc          scanf
#define pr          printf
#define whi         while
#define ll          long long
#define ull         unsigned long long
#define lld         I64d
#define ff          first
#define ss          second
#define vc          vector
#define pb          push_back
#define ite         iterator
#define str         string
#define bl          bool
#define tr          true
#define fl          false
#define ct          continue;
#define endl        '\n'
#define ret         return
#define rsort       greater<int>()
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)





int main()
{
    int n,m,k;
    sc("%d%d%d",&n,&m,&k);
    int mousex,mousey,cat1x,cat1y,cat2x,cat2y;
    whi(k--)
    {
        sc("%d%d%d%d%d%d",&mousex,&mousey,&cat1x,&cat1y,&cat2x,&cat2y);
        if(mousex<=min(cat1x,cat2x) or mousex>=max(cat1x,cat2x) or
           mousey<=min(cat1y,cat2y) or mousey>=max(cat1y,cat2y))
        {
            pr("YES\n");
            ct
        }
        if(cat1x>cat2x) swap(cat1x,cat2x),swap(cat1y,cat2y);
        if(abs(mousex-cat1x)<abs(mousey-cat1y) or
           abs(mousex-cat2x)<abs(mousex-cat2x))
        {
            pr("YES\n");
            ct
        }
        if(cat1y>cat2y) swap(cat1x,cat2x),swap(cat1y,cat2y);
        if(abs(mousey-cat1y)<abs(mousex-cat1x) or
           abs(mousey-cat2y)<abs(mousex-cat2x))
        {
            pr("YES\n");
            ct
        }
        pr("NO\n");
    }
    ret 0;
}
