#include "bits/stdc++.h"
using namespace std;
const int N=1e6,M=10;
int f[M],ans;
set <int> s;

void go(int i)
{
	s.insert(i);
	int sum=0;
	while(i) sum+=f[i%10],i/=10;
	if(s.find(sum)==s.end()) go(sum);
}

int main()
{
	f[0]=1;
	for(int i=1;i<M;i++) f[i]=i*f[i-1];

	for(int i=1;i<N;i++)
	{
		s.clear();
		go(i);
		if(s.size()==60) ans++;
	}
	printf("%d",ans);
}