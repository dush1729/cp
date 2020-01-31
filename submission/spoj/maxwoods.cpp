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

int n,m,i,j,trees[209][209],ans;
char a[209][209];
void init()
{
    for(i=0;i<n;i++) for(j=0;j<m;j++) trees[i][j]=0;
}
bl blocked;
int main()
{
    tc
    {
        sc("%d%d",&n,&m);
        for(i=0;i<n;i++) sc(" %s",a[i]);
        if(a[0][0]=='#')
        {
            pr("0\n");
            ct;
        }
        init();
        if(a[0][0]=='T') trees[0][0]=1;
        ans=trees[0][0];
        blocked=fl;
        for(i=1;i<m;i++)
        {
            if(blocked==tr) trees[0][i]=-99999999;
            else if(a[0][i]=='#') blocked=tr,trees[0][i]=-99999999;
            else if(a[0][i]=='T') trees[0][i]=trees[0][i-1]+1;
            else if(a[0][i]=='0') trees[0][i]=trees[0][i-1];
            ans=max(ans,trees[0][i]);
        }
        for(i=1;i<n;i++)
        {
            if(i%2==0) //forward
            {
                if(a[i-1][0]=='#' or a[i][0]=='#') trees[i][0]=-99999999;
                else if(a[i][0]=='T') trees[i][0]=trees[i-1][0]+1;
                else trees[i][0]=trees[i-1][0];
                ans=max(ans,trees[i][0]);
                for(j=1;j<m;j++)
                {
                    if(a[i][j]=='#') trees[i][j]=-99999999;
                    else if(a[i][j]=='T')
                        trees[i][j]=max(trees[i-1][j],trees[i][j-1])+1;
                    else trees[i][j]=max(trees[i-1][j],trees[i][j-1]);
                    ans=max(ans,trees[i][j]);
                }
            }
            else       //backward
            {
                if(a[i-1][m-1]=='#' or a[i][m-1]=='#') trees[i][m-1]=-99999999;
                else if(a[i][m-1]=='T') trees[i][m-1]=trees[i-1][m-1]+1;
                else trees[i][m-1]=trees[i-1][m-1];
                ans=max(ans,trees[i][m-1]);
                for(j=m-2;j>=0;j--)
                {
                    if(a[i][j]=='#') trees[i][j]=-99999999;
                    else if(a[i][j]=='T')
                        trees[i][j]=max(trees[i-1][j],trees[i][j+1])+1;
                    else trees[i][j]=max(trees[i-1][j],trees[i][j+1]);
                    ans=max(ans,trees[i][j]);
                }
            }
        }
        pr("%d\n",ans);
    }
    ret 0;
}
