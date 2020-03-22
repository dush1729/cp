#include "bits/stdc++.h"
using namespace std;
const int N=1e5+20,MAX=1<<10;
int t,n,q,x,p,a[N],bit[MAX],tc;
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<MAX;i++) bit[i]=bit[i>>1]+(i&1);

	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			a[i]=a[i-1]^(bit[x]&1);
		}

		cout<<"Case #"<<++tc<<": ";
		while(q--)
		{
			cin>>p>>x;
			p++;
			if(a[p]^a[p-1]^(bit[x]&1))
				for(int j=p;j<=n;j++) a[j]^=1;
			
			if(a[n]==0) cout<<n;
			else
			{
				int l=0,r=0;
				for(int i=1;i<=n and l==0;i++)
					if(a[i]==1) l=i;
				for(int i=n;i>=1 and a[i]==1;i--) r=i;
				cout<<max({l-1,n-l,r-1,n-r});
			}
			cout<<" ";
		}
		cout<<"\n";
	}
}
