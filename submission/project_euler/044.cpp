#include <bits/stdc++.h>
using namespace std;
const int N=1e7+20;
int i,mn=INT_MAX;
bool pent[N];
vector <int> v;
int main()
{
	for(i=1;;i++)
	{
		int val=i*(3*i-1)/2;
		if(val<N) pent[val]=true, v.push_back(val);
		else break;
	}
	
	for(auto i:v)
		for(auto j:v)
			if(i+j<N and pent[i+j] and pent[abs(i-j)]) mn=min(mn,abs(i-j));
	cout<<mn;
}
