#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int i,j,ans;
bool b[N];
bool circular_primes(string a)
{
	for(int i=0;i<a.size();i++)
	{
		a=a.substr(1,a.size()-1)+a[0];
		if(b[stoi(a)]) return false;
	}
	
	return true;
}
int main()
{
	for(i=2;i*i<N;i++)
		if(!b[i])
			for(j=i*i;j<N;j+=i)
				b[j]=true;

	for(i=2;i<N;i++) ans+=circular_primes(to_string(i));

	printf("%d\n",ans);
}
