#include<bits/stdc++.h>
using namespace std;
int testvariable=1;
#define sc scanf
#define pr printf
#define whi while
#define ll long long
#define ull unsigned long long
#define lld I64d
#define mp make_pair
#define ff first
#define ss second
#define vc vector
#define pb push_back
#define bg begin
#define iter iterator
#define str string
#define bl bool
#define tr true
#define fl false
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define ret return
#define sz size
#define rsort greater<int>()
#define nl pr("\n");
#define fnl cout<<"\n";
#define test pr("TEST %d\n",testvariable);testvariable++;
#define ftest cout<<"TEST "<<testvariable<<"\n";testvariable++;
#define vi vc<int>
#define vs vc<str>
#define vll vc<ll>
#define gcd(a,b)  __gcd(a,b)
#define MOD 1000000007

#define vi vc<int>
#define vll vc<ll>
#define vs vc<str>

#define mpi map<int,int>
#define mpll map<ll,ll>
#define mps map<str,int>
#define miti map<int,int>::iter
#define mplli map<ll,ll>::iter
#define mpsi map<str,int>::iter

#define all(c) c.begin(),c.end()
#define sz(c) c.size()
#define clr(c) c.clear()
ll a[100000],b[100000];
int main()
{
    int T;
    sc("%d",&T);
    whi(T--)
    {
        int i,N;
        sc("%d",&N);
        for(i=0;i<N;i++) sc("%lld",&a[i]);
        for(i=0;i<N;i++) sc("%lld",&b[i]);
        bl ans=tr;
        ll mn=min(a[0],b[0]);
        for(i=1;i<N;i++)
        {
            if(min(a[i],b[i])>=mn)
            {
                mn=min(a[i],b[i]);
            }
            else if(max(a[i],b[i])>=mn)
            {
                mn=max(a[i],b[i]);
            }
            else
            {
                ans=fl;
                break;
            }
        }
        if(ans) pr("YES\n");
        else pr("NO\n");
    }
    ret 0;
}
