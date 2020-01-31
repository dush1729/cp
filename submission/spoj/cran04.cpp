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
#define rsort(a)    greater<a>
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define minof(a)    std::numeric_limits<a>::min()
#define maxof(a)    std::numeric_limits<a>::max()

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

ll k,i,ans,len;
char a[3000999];
ll b[3000999],freq[3000999];
int main()
{
    tc
    {
        sc("%lld%lld",&len,&k);
        sc(" %s",a);
        for(i=0;i<3000999;i++) b[i]=freq[i]=0;
        ans=0;
        if(k==0)
        {
            ll cnt_zero=0;
            for(i=0;i<len;i++)
            {
                if(a[i]=='0') cnt_zero++;
                else
                {
                    ans+=cnt_zero*(cnt_zero+1)/2;
                    cnt_zero=0;
                }
            }
            ans+=cnt_zero*(cnt_zero+1)/2;
            pr("%lld\n",ans);
            ct
        }
        b[0]=(a[0]=='0'?0:1);
        freq[b[0]]++;
        for(i=1;i<len;i++) b[i]=b[i-1]+(a[i]=='0'?0:1),freq[b[i]]++;
        for(i=0;i<len;i++)
        {
            if(a[i]=='1')
            {
                if(b[i]+k-1<=b[len-1]) ans+=freq[b[i]+k-1];
                else break;
            }
            else
            {
                if(b[i]+k<=b[len-1]) ans+=freq[b[i]+k];
                else break;
            }
        }
        pr("%lld\n",ans);
    }
    ret 0;
}
