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
#define mnlim(a)    std::numeric_limits<a>::min()
#define mxlim(a)    std::numeric_limits<a>::max()

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)


ll m,n,i,a[100000],ans=0,counter;
ll given,height,remaining,x;
int main()
{
    sc("%lld%lld",&m,&n);
    for(i=0;i<n;i++) sc("%lld",&a[i]);
    sort(a,a+n);
    counter=1;
    given=0;
    height=a[n-1];
    for(i=n-2;i>=0;i--)    //5 10 18 20
    {
        if(counter*(a[i+1]-a[i])+given<=m)
        {
            given+=counter*(a[i+1]-a[i]);
            height=a[i];
        }
        else
        {
            x=ceil(1.*a[i+1]-(1.*(m-given)/counter));
            given+=counter*(a[i+1]-x);
            height=x;
            break;
        }
        counter++;
    }
    remaining=m-given;
    for(i=0;i<n;i++)
    {
        if(a[i]<height) ans+=a[i]*a[i];
        else if(remaining>0)
        {
            ans+=(height-1)*(height-1);
            remaining--;
        }
        else ans+=height*height;
    }
    pr("%lld",ans);
    ret 0;
}
