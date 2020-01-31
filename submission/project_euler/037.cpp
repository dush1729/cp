#include <bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int i,j,cnt,sum,ans;
bool p[N];
bool ok(string a)
{
	string b=a;
	while(!a.empty() and !p[stoi(a)]) a.pop_back();
	while(!b.empty() and !p[stoi(b)]) b.erase(0,1);
	return a.empty() and b.empty();
}
int main()
{
	p[1]=true;
	for(i=2;i*i<N;i++)
		if(!p[i])
			for(j=i*i;j<N;j+=i)
				p[j]=true;

	for(i=8;cnt<11;i++)
		if(ok(to_string(i))) ans+=i, cnt++;

	cout<<ans;
}
