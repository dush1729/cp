#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,a[N],dp[N];
stack <int> s;

int main()
{
	ios::sync_with_stdio(0);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		while(not s.empty() and a[s.top()]>a[i])
		{
			dp[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	for(int i=1;i<=n;i++) printf("%d ",dp[i]);
}