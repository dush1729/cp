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

int f,s,g,u,d;
//f -> total floors
//s -> current
//g -> target
//u -> up
//d -> down
vc <int> moves(1000001,99999999);
void bfs(int a)
{
    moves[a]=0;
    queue <int> q;
    if(a+u<=f) q.push(a+u);
    if(a-d>=1) q.push(a-d);
    whi(q.empty()==fl)
    {
        a=q.front();
        q.pop();
        if(a-u>=1 and moves[a-u]+1<moves[a])
        {
            moves[a]=moves[a-u]+1;
            if(a+u<=f) q.push(a+u);
            if(a-d>=1) q.push(a-d);
        }
        else if(a+d<=f and moves[a+d]+1<moves[a])
        {
            moves[a]=moves[a+d]+1;
            if(a+u<=f) q.push(a+u);
            if(a-d>=1) q.push(a-d);
        }
    }
}
int main()
{
    sc("%d%d%d%d%d",&f,&s,&g,&u,&d);
    bfs(s);
    if(moves[g]==99999999) pr("use the stairs");
    else pr("%d",moves[g]);
    ret 0;
}
