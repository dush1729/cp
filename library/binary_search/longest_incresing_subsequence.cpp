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

	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		if(j==v.size()) v.push_back(a[i]);
		else v[j]=a[i];
	}

	cout<<v.size()<<endl;
}