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

int n,m,i,j,a[200][200],dist[200][200];
char zz[200][200];
void bfs(int x,int y)
{
    dist[x][y]=0;
    queue <pair<int,int>> q;
    q.push({x,y});
    whi(q.empty()==fl)
    {
        x=q.front().ff;
        y=q.front().ss;
        q.pop();
        if(x+1<n and dist[x+1][y]==-1 or dist[x+1][y]>dist[x][y]+1)
        {
            dist[x+1][y]=dist[x][y]+1;
            q.push({x+1,y});
        }
        if(y+1<m and dist[x][y+1]==-1 or dist[x][y+1]>dist[x][y]+1)
        {
            dist[x][y+1]=dist[x][y]+1;
            q.push({x,y+1});
        }
        if(x-1>=0 and dist[x-1][y]==-1 or dist[x-1][y]>dist[x][y]+1)
        {
            dist[x-1][y]=dist[x][y]+1;
            q.push({x-1,y});
        }
        if(y-1>=0 and dist[x][y-1]==-1 or dist[x][y-1]>dist[x][y]+1)
        {
            dist[x][y-1]=dist[x][y]+1;
            q.push({x,y-1});
        }
    }
}
int main()
{
    tc
    {
        sc("%d%d",&n,&m);
        for(i=0;i<n;i++) sc(" %s",zz[i]);
        for(i=0;i<n;i++) for(j=0;j<m;j++) a[i][j]=zz[i][j]-'0',dist[i][j]=INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==1) bfs(i,j);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) pr("%d ",dist[i][j]);
            pr("\n");
        }
    }
    ret 0;
}
