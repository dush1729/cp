#include "bits/stdc++.h"
using namespace std;

int n;
map <int,vector <int>> adj;
queue <int> q;
map <int,int> dp;
set <int> done;
vector <int> a;

bool valid(int x)
{
	return x>=0 and x<n and dp.find(x)==dp.end();
}

void add(int x,int v)
{
	q.push(x);
	dp[x]=v;
}

void go()
{
	add(0,0);
	while(not q.empty())
	{
		int node=q.front();
		q.pop();
		//cout<<node<<" "<<dp[node]<<endl;

		if(valid(node-1)) add(node-1,dp[node]+1);
		if(valid(node+1)) add(node+1,dp[node]+1);
		if(done.find(a[node])==done.end())
		{
			for(auto child:adj[a[node]])
				if(valid(child)) add(child,dp[node]+1);
			done.insert(a[node]);
		}
	}
}

class Solution
{
public:
	int minJumps(vector<int>& arr)
	{
		a=arr;
		adj.clear(),dp.clear(),done.clear();
		n=a.size();
		for(int i=0;i<n;i++)
			adj[a[i]].push_back(i);

		go();
		return dp[n-1];
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif