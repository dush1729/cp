#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vll vector <ll>
#define vvll vector <vll>
const int MOD=1e9+7;
int t,n,m;

ll add(ll a,ll b){return (a+b)%MOD;}
ll mul(ll a,ll b){return (a*b)%MOD;}

vvll multiply_matrices(vvll &a,vvll &b)
{
	int n=a.size();
	vvll ans(n,vll(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				ans[i][j]=add(ans[i][j],mul(a[i][k],b[k][j]));
	return ans;
}

int power(int x)
{
	vvll p={{1,1},{1,0}},ans={{1,0},{0,1}};
	for(int i=0;i<31;i++)
	{
		if(x&(1<<i)) ans=multiply_matrices(ans,p);
		p=multiply_matrices(p,p);
	}
	return ans[0][0];
}


int fib(int x)
{
	if(x<=1) return x;
	return power(x-1);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",(fib(m+2)-fib(n+1)+MOD)%MOD);
	}
}
