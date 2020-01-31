#include "bits/stdc++.h"
using namespace std;
int a,b,p[9],i;
long long dp[2][20],ans1,ans2;
string s;

long long go(int idx,bool smaller)
{
	long long &ans=dp[smaller][idx];
	if(ans!=-1) return ans;
	if(idx+1==s.size()) return ans=(smaller?45:(s[idx]-'0')*(s[idx]-'0'+1)/2);
	
	ans=0;
	for(int i=smaller?9:s[idx]-'0';i>=0;i--)
	{
		smaller|=(i<s[idx]-'0');
		if(smaller) ans+=1ll*i*p[s.size()-idx-1];
		else ans+=1ll*i*(stoi(string(s.begin()+idx+1,s.end()))+1);
		ans+=go(idx+1,smaller);
	}
	return ans;
}

int main()
{
	p[0]=1;
	for(i=1;i<9;i++) p[i]=p[i-1]*10;
	
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==-1) break;
		
		ans1=ans2=0;
		s=to_string(b);
		memset(dp,-1,sizeof dp);
		ans1=go(0,false);
		
		s=to_string(a-1);
		memset(dp,-1,sizeof dp);
		ans2=go(0,false);
		
		printf("%lld\n",ans1-ans2);
	}
}
