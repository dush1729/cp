#include<bits/stdc++.h>
using namespace std;
int yt=1;           //test variable
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
#define mp          make_pair
#define ff          first
#define ss          second
#define vc          vector
#define pb          push_back
#define ite         iterator
#define str         string
#define bl          bool
#define tr          true
#define fl          false

#define endl        '\n'
#define ret         return
#define rsort       greater<int>()
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define test        if(qf==tr) pr("TEST %d\n",yt++);else cout<<"TEST "<<yt++<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

#define si(n)       if(qf==fl) sc("%d",&n); else cin>>n;
#define sll(n)      if(qf==fl) sc("%lld",&n); else cin>>n;
#define pi(n)       if(qf==fl) pr("%d ",n); else cout<<n<<" ";
#define pll(n)      if(qf==fl) pr("%lld ",n); else cout<<n<<" ";

#define tc          int t;if(qf==fl) si(t) else cin>>t;whi(t--)
#define ct          continue;
#define debug       system("PAUSE");
int main()
{
    int n,k,i,x;
    sc("%d%d",&n,&k);
    set <int> a;
    set <int>::ite it;
    int count=0;
    for(i=0;i<n;i++) sc("%d",&x),ins(a,x);
    for(it=bg(a);it!=ed(a);it++)
    {
        if(fd(a,*it-k)!=ed(a)) count++;
        if(fd(a,*it+k)!=ed(a)) count++;
    }
    pr("%d",count/2);
    ret 0;
}
