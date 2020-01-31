#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

vector <int> v;
int n,a[N];

int main()
{
	//https://www.interviewbit.com/problems/longest-increasing-subsequence/
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];

	v.push_back(a[1]);
	for(int i=2;i<=n;i++)
	{
		auto it=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		if(it==v.size()) v.push_back(a[i]);
		else v[it]=a[i];
	}
	cout<<v.size()<<endl;
}