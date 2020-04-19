#include "bits/stdc++.h"
using namespace std;

const int MOD=1e9;

int t,tc;
string a;
stack <vector <int>> s;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a;

		int n=a.size();
		int dx=0,dy=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='(')
			{
				s.push({dx,dy,a[i-1]-'0'});
				dx=dy=0;
			}
			else if(a[i]==')')
			{
				auto v=s.top();
				s.pop();

				dx=v[0]+(1ll*dx*v[2])%MOD,dy=v[1]+(1ll*dy*v[2])%MOD;
			}
			else if(a[i]>='0' and a[i]<='9') continue;
			else
			{
				if(a[i]=='S') dy++;
				else if(a[i]=='E') dx++;
				else if(a[i]=='N') dy--;
				else dx--;
			}
			dx%=MOD,dy%=MOD;
			if(dx<0) dx+=MOD;
			if(dy<0) dy+=MOD;
		}


		cout<<"Case #"<<++tc<<": "<<++dx<<" "<<++dy<<"\n";
	}
}