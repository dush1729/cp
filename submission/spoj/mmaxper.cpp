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

#define dalo        insert
#define dalo        push_back
int main()
{
    int n,i,a,b,h1,m1,h2,m2,mx,ans1,ans2,temp1,temp2;
    sc("%d%d%d",&n,&a,&b);
    h1=a;
    m1=b;
    h2=b;
    m2=a;
    for(i=1;i<n;i++)
    {
        sc("%d%d",&a,&b);
        mx=INT_MIN;
        if(mx<m1+abs(h1-a)+b)
        {
            mx=m1+abs(h1-a)+b;
            ans1=mx;
            ans2=a;
        }
        if(mx<m2+abs(h2-a)+b)
        {
            mx=m2+abs(h2-a)+b;
            ans1=mx;
            ans2=a;
        }
        temp1=ans2;
        temp2=ans1;

        mx=INT_MIN;
        if(mx<m1+abs(h1-b)+a)
        {
            mx=m1+abs(h1-b)+a;
            ans1=mx;
            ans2=b;
        }
        if(mx<m2+abs(h2-b)+a)
        {
            mx=m2+abs(h2-b)+a;
            ans1=mx;
            ans2=b;
        }

        h1=temp1;
        m1=temp2;

        h2=ans2;
        m2=ans1;
    }
    pr("%d",max(m1,m2));
    ret 0;
}
