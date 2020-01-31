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
int f[100001],i,j,r,mn,val1,val2;
vc <bl> prime(100001,tr);
int main()
{
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(i=4;i<=100000;i+=2) prime[i]=fl;
    r=sqrt(100000);
    for(i=3;i<=r;i+=2)
    {
        if(prime[i]==tr)
        {
            for(j=i*i;j<100001;j+=i) prime[j]=fl;
        }
        if(i%6==1) i+=2;
    }
    for(i=3;i<100001;i++)
    {
        if(prime[i]==tr)
        {
            f[i]=0;
            ct;
        }
        mn=INT_MAX;
        r=sqrt(i);
        for(j=1;j<=r;j++)
        {
            if(i%j==0)
            {
                mn=min(mn,j+(i/j));
                val1=j;
                val2=i/j;
            }
        }
        f[i]=f[val1]+f[val2];
    }
    int x;
    sc("%d",&x);
    pr("%d",f[x]);
    ret 0;
}
