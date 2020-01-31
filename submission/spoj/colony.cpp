#include<bits/stdc++.h>
using namespace std;
bool qf=false;      //fast io enabled/disabled
#define input       freopen("in.txt","r",stdin);
#define output      freopen("out.txt","w",stdout);
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);qf=true;
#define ll          long long
#define ull         unsigned long long
#define lld         I64d
#define endl        '\n'
#define rsort(a)    greater<a>()
#define nl          if(qf==true) printf("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

#define mod         1000000007
const int N = 1e5 + 9;

ll y,p,color=1,path,tp,i;
set <ll> s;
int main()
{
    scanf("%lld%lld",&y,&p);
    p+=(1LL<<y);
    tp=p;
    while(p!=1) s.insert(p),p/=2;
    p=tp;
    i=1;
    while(i<p)
    {
        if(s.find(i*2)!=s.end()) path=1, i*=2;
        else path=2,i=i*2+1;
        if(path==1)
        {
            if(color==1) color=2;
            else color=1;
        }
    }
    if(color==2) printf("blue");
    else printf("red");
    return 0;
}

