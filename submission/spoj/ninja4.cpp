/*
Silly Mistakes
1. Wrong array size(100 instead of 101)
2. Wrong variable used due to typing mistake(j instead of i)
3. i/25 is not equal to i/25.0
4. Using variables which have garbage values
5. Not using constants like l for double and LL for long long

Silly Hacks
1. Applying hack when some unknown function is used
2. Wrong analysis of complexity and doing hack thinking it will give TLE

Before Contest
1. One hour rest
2. Poop!
3. Files ready in CB
4. Full Stomach

During contest
1. First solve all problems, then lock and hack.
2. Avoid wrong hacks

After contest
1. Upsolve
*/
#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define wh while
#define ll long long
#define ull unsigned long long
#define lld I64d
#define whi while
#define mp make_pair
#define ff first
#define ss second
#define vc vector
#define pb push_back
#define st string
#define bl bool
#define tr true
#define fl false
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false)
int main()
{
    int T;
    sc("%d",&T);
    whi(T--)
    {
        ll n,x,y,t;
        sc("%lld",&n);
        t=(n+3)/4;
        x=t*(2+(t-1)*4)/2;
        t=(n+1)/4;
        x-=t*(6+(t-1)*4)/2;
        t=(n+2)/4;
        y=t*(4+(t-1)*4)/2;
        t=n/4;
        y-=t*(8+(t-1)*4)/2;
        pr("%lld %lld\n",x,y);
    }
    return 0;
}
