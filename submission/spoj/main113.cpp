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
#define rsort(a)    greater<a>()
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

ll n,i,j,k,a[3][3],b[3][3],ans;
int main()
{
    tc
    {
        sc("%lld",&n);
        if(n==1)
        {
            pr("3\n");
            ct;
        }
        if(n==2)
        {
            pr("9\n");
            ct;
        }
        ans=0;
        for(i=0;i<3;i++) for(j=0;j<3;j++) a[i][j]=b[i][j]=1;
        for(i=2;i<n;i++)
        {
            b[0][0]=b[1][0]=b[2][0]=a[0][0]+a[0][1]+a[0][2];
            b[0][1]=b[1][1]=b[2][1]=a[1][0]+a[1][1]+a[1][2];
            b[0][2]=b[1][2]=b[2][2]=a[2][0]+a[2][1]+a[2][2];

            b[2][0]-=a[0][1];
            b[1][0]-=a[0][2];
            b[2][1]-=a[1][0];
            b[0][1]-=a[1][2];
            b[1][2]-=a[2][0];
            b[0][2]-=a[2][1];
            for(j=0;j<3;j++) for(k=0;k<3;k++) a[j][k]=b[j][k];
        }
        for(i=0;i<3;i++) for(j=0;j<3;j++) ans+=a[i][j];
        pr("%lld\n",ans);
    }
    ret 0;
}
