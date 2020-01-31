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


int height[8][8],previ;
bl valid(int x,int y)
{
    if(x<0 or y<0 or x>=8 or y>=8) ret fl;
    ret tr;
}
void init()
{
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) height[i][j]=12345678;
}
void bfs(int x,int y)
{
    init();
    height[x][y]=0;
    queue <pair<int,int>> q;
    if(valid(x+1,y+2)) q.push({x+1,y+2});
    if(valid(x+1,y-2)) q.push({x+1,y-2});
    if(valid(x-1,y+2)) q.push({x-1,y+2});
    if(valid(x-1,y-2)) q.push({x-1,y-2});
    if(valid(x+2,y+1)) q.push({x+2,y+1});
    if(valid(x+2,y-1)) q.push({x+2,y-1});
    if(valid(x-2,y+1)) q.push({x-2,y+1});
    if(valid(x-2,y-1)) q.push({x-2,y-1});
    whi(q.empty()==fl)
    {
        x=q.front().ff;
        y=q.front().ss;
        q.pop();
        previ=height[x][y];
        height[x][y]=min({
                          (valid(x+1,y+2)?height[x+1][y+2]:12345678)+1,
                          (valid(x+1,y-2)?height[x+1][y-2]:12345678)+1,
                          (valid(x-1,y+2)?height[x-1][y+2]:12345678)+1,
                          (valid(x-1,y-2)?height[x-1][y-2]:12345678)+1,

                          (valid(x+2,y+1)?height[x+2][y+1]:12345678)+1,
                          (valid(x+2,y-1)?height[x+2][y-1]:12345678)+1,
                          (valid(x-2,y+1)?height[x-2][y+1]:12345678)+1,
                          (valid(x-2,y-1)?height[x-2][y-1]:12345678)+1,
                          height[x][y]
                         });
        if(height[x][y]!=previ)
        {
            if(valid(x+1,y+2)) q.push({x+1,y+2});
            if(valid(x+1,y-2)) q.push({x+1,y-2});
            if(valid(x-1,y+2)) q.push({x-1,y+2});
            if(valid(x-1,y-2)) q.push({x-1,y-2});
            if(valid(x+2,y+1)) q.push({x+2,y+1});
            if(valid(x+2,y-1)) q.push({x+2,y-1});
            if(valid(x-2,y+1)) q.push({x-2,y+1});
            if(valid(x-2,y-1)) q.push({x-2,y-1});
        }
    }
}
int main()
{
    char a[3],b[3];
    tc
    {
        sc(" %s %s",a,b);
        bfs(a[0]-'a',a[1]-'1');
        pr("%d\n",height[b[0]-'a'][b[1]-'1']);
    }
    ret 0;
}
