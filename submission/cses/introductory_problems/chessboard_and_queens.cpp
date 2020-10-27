#include "bits/stdc++.h"
using namespace std;

const int N=8;

char a[N][N+1];
vector <int> v;
int ans;

int main()
{
	for(int i=0;i<N;i++)
	{
		scanf(" %s",a[i]);
		v.push_back(i);
	}

	do
	{
		set <int> d1,d2;
		bool valid=true;
		for(int i=0;i<N and valid;i++)
		{
			if(a[i][v[i]]=='*') valid=false;
			if(d1.find(i+v[i])==d1.end()) d1.insert(i+v[i]);
			else valid=false;
			if(d2.find(i-v[i])==d2.end()) d2.insert(i-v[i]);
			else valid=false;
		}
		ans+=valid;
	}
	while(next_permutation(v.begin(),v.end()));
	
	printf("%d",ans);
}