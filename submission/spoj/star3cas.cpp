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
int n,i,a[21],steps[21],x;
void init()
{
    for(i=0;i<=n;i++) steps[i]=INT_MAX;
}
void bfs()
{
    init();
    queue <int> q;
    q.push(0);
    steps[0]=0;
    whi(q.empty()==fl)
    {
        x=q.front();
        q.pop();
        if(x+1<=n and steps[x+1]>steps[x]+1)
        {
            q.push(x+1);
            steps[x+1]=steps[x]+1;
        }
        if(x+a[x]>=0 and x+a[x]<=n and steps[x+a[x]]>steps[x]+1)
        {
            q.push(x+a[x]);
            steps[x+a[x]]=steps[x]+1;
        }
    }
}

int main()
{
    tc
    {
        sc("%d",&n);
        for(i=0;i<n;i++) sc("%d",&a[i]);
        a[n]=100;
        bfs();
        pr("%d\n",steps[n]);
    }
    ret 0;
}
