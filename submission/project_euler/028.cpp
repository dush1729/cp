#include "bits/stdc++.h"
using namespace std;

int f(int x,int y)
{
	return (x-2)*(x-2)+y*(x-1);
}

int main()
{
	int ans=0;
	for(int i=1;i<=1001;i+=2)
		for(int j=1;j<=4;j++)
			ans+=f(i,j);
	cout<<ans-3<<endl;
}
