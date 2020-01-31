#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+20,D=10;
int i,j;
string ans;
int main()
{
	for(i=1;i<MAX;i++)
	{
		bool f[D]={},ok=true;
		
		string a="";
		for(j=1;ok;j++)
		{
			string s=to_string(i*j);
			for(auto i:s)
			{
				if(i=='0' or f[i-'0'])
				{
					ok=false;
					break;
				}
				else f[i-'0']=true;
			}
			
			if(ok) a+=s;
		}
		
		ok=true;
		for(j=1;j<D;j++) ok&=f[j];

		if(ok) ans=max(ans,a);
	}
	
	cout<<ans;
}
