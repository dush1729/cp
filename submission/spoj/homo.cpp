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
#define ct          continue
#define endl        '\n'
#define ret         return
#define rsort(a)    greater<a>
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define minof(a)    std::numeric_limits<a>::min()
#define maxof(a)    std::numeric_limits<a>::max()
#define setval(a,v) memset(a,v,sizeof(a));

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

int n,val;
char a[20];
multiset <int> s1;
set <int> s2;
bl homo,hetro;
int main()
{
    sc("%d",&n);
    whi(n--)
    {
        sc(" %s%d",a,&val);
        if(strcmp(a,"insert")==0)
        {
            if(fd(s1,val)==ed(s1))
            {
                ins(s1,val);
                ins(s2,val);
            }
            else ins(s1,val);
        }
        else
        {
            if(s1.count(val)==0) ;
            else if(s1.count(val)==1)
            {
                rem(s1,val);
                rem(s2,val);
            }
            else rem(s1,fd(s1,val));
        }
        if(sz(s1)==sz(s2)) homo=fl;
        else homo=tr;
        if(sz(s2)>1) hetro=tr;
        else hetro=fl;
        if(hetro and homo) pr("both\n");
        else if(homo) pr("homo\n");
        else if(hetro) pr("hetero\n");
        else pr("neither\n");
    }
    ret 0;
}
