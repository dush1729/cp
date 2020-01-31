#include "bits/stdc++.h"
using namespace std;
const int N=1e6+20;
bool b[N];
map <string,vector <int>> m;
int main()
{
	for(int i=2;i*i<N;i++)
		if(not b[i])
			for(int j=i*i;j<N;j+=i) b[j]=true;
	for(int num=1e5;num<N;num++)
	{
		if(b[num]) continue;
		for(int i=0;i<4;i++)
		{
			for(int j=i+1;j<5;j++)
			{
				for(int k=j+1;k<6;k++)
				{
					string a=to_string(num);
					if(a[i]==a[j] and a[j]==a[k])
					{
						a[i]=a[j]=a[k]='*';
						m[a].push_back(num);
					}
				}
			}
		}
	}

	for(auto i:m)
	{
		if(i.second.size()!=8) continue;
		cout<<i.first<<" ";
		for(auto j:i.second) cout<<j<<" ";cout<<endl;
	}
}