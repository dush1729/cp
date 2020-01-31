#include<bits/stdc++.h>
using namespace std;
int testvariable=1;

#define read        freopen("in.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

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
#define nl          pr("\n");
#define fnl         cout<<"\n";
#define test        pr("TEST %d\n",testvariable++);
#define ftest       cout<<"TEST "<<testvariable++<<"\n";
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

#define si(n)       sc("%d",&n)
#define sll(n)      sc("%lld",&n)
#define pi(n)       pr("%d ",n)
#define pll(n)      pr("%lld ",n)

#define tc          int t;si(t);whi(t--)
#define ftc         int t;cin>>t;whi(t--)
int v1[100000],v2[100000];
int main()
{
    whi(1)
    {
        int n1,i,n2,j,chunk1,chunk2,ans=0,st1,st2,end1,end2;
        si(n1);
        if(n1==0) break;
        for(i=0;i<n1;i++) si(v1[i]);
        si(n2);
        for(i=0;i<n2;i++) si(v2[i]);
        for(i=0,j=0;i<n1 or j<n2;)
        {
            chunk1=chunk2=0;
            st1=i;
            st2=j;
            whi(i<n1 and j<n2 and v1[i]!=v2[j])
            {
                if(v1[i]>v2[j]) j++;
                else i++;
            }
            if(i==n1) j=n2;
            else if(j==n2) i=n1;
            else
            {
                i++;
                j++;
            }
            end1=i;
            end2=j;
            for(i=st1;i!=end1;i++) chunk1+=v1[i];
            for(i=st2;i!=end2;i++) chunk2+=v2[i];
            i=end1;
            ans+=max(chunk1,chunk2);
        }
        pr("%d\n",ans);
    }
    ret 0;
}
