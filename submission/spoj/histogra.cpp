/*
Silly Mistakes
1. Wrong array size(100 instead of 101)
2. Wrong variable used due to typing mistake(j instead of i)
3. i/25 is not equal to i/25.0
4. Using variables which have garbage values
5. Not using constants like l for double and LL for long long

Silly Hacks
1. NO HACK BECOZ YOU ARE STUPID. ;_;

Doesn't matter. Applying hack when some unknown function is used
Doesn't matter. Wrong analysis of complexity and doing hack thinking it will give TLE

Before Contest
1. One hour rest
2. Poop!
3. Files ready in CB
4. Full Stomach

During contest
1. CONCENTRATE!
2. First solve all problems, then lock and hack.
3. Avoid wrong hacks

After contest
1. Upsolve
*/
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
ll a[100000],st[100000];
int main()
{
    whi(1)
    {
        ll n,i,j,top=-1,mx=0,area,lh;
        sc("%lld",&n);
        if(n==0) break;
        for(i=0;i<n;i++) sc("%lld",&a[i]);
        i=0;
        whi(i<n)
        {
            if(top==-1 or a[st[top]]<=a[i]) st[++top]=i++;
            else
            {
                lh=st[top];
                top--;
                if(top!=-1) area=a[lh]*(i-st[top]-1);
                else area=a[lh]*(i);
                mx=max(area,mx);
            }
        }
        whi(top!=-1)
        {
            lh=st[top];
            top--;
            if(top!=-1) area=a[lh]*(i-st[top]-1);
            else area=a[lh]*(i);
            mx=max(area,mx);
        }
        pr("%lld\n",mx);
    }
    ret 0;
}
