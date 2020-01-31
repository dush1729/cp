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
int a[200000];
ll inv=0;
void merge(int a[],int start,int mid,int end)
{
    int i,p=start,q=mid+1,arr[end-start+1],k=0;
    for(i=start;i<=end;i++)
    {
        if(p>mid) arr[k++]=a[q++];
        else if(q>end) arr[k++]=a[p++];
        else if(a[p]<a[q]) arr[k++]=a[p++];
        else
        {
            inv+=mid-p+1;
            arr[k++]=a[q++];
        }
    }
    for(i=0;i<k;i++) a[start++]=arr[i];
}
void mergesort(int a[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
inline int
fast_input()
{
    int num = 0;
    	char c = getchar_unlocked();
    	int flag = 0;
    	while(!((c>='0' & c<='9') || c == '-'))
    	    c=getchar_unlocked();
    	if(c == '-')
    	{
    	    flag = 1;
    	    c=getchar_unlocked();
    	}
    	while(c>='0' && c<='9')
    	{
    	    num = (num<<1)+(num<<3)+c-'0';
    	    c=getchar_unlocked();
    	}
    	if(flag==0)
    	    return num;
    	else
    	    return -1*num;
}
int main()
{
    int t;
    t=fast_input();
    whi(t--)
    {
        inv=0;
        int n,i;
        n=fast_input();
        for(i=0;i<n;i++) a[i]=fast_input();
        mergesort(a,0,n-1);
        pr("%lld\n",inv);
    }
    ret 0;
}
