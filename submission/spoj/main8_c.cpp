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



ll n,k,i,lo,hi,mid,stud,ans;
ll a[50000];
int main()
{
    tc
    {
        sc("%lld%lld",&n,&k);
        for(i=0;i<n;i++) sc("%lld",&a[i]);
        lo=0;
        hi=10000000001;
        whi(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(mid==0)
            {
                if(k>n) ans=0;
                else ans=1;
                break;
            }
            stud=0;
            for(i=0;i<n;i++) stud+=a[i]/mid;
            if(stud>=k)
            {
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        pr("%lld\n",ans);
    }
    ret 0;
}
