#include "solution.hpp"
using namespace std;

const int N=1e5+20;

int n;
vector <int> adj[N];
vector <vector <int>> cc;
bool vis[N];

void dfs(int node)
{
	cc.back().push_back(node);
	vis[node]=true;
	for(auto child:adj[node])
		if(not vis[child]) dfs(child);
}

class Solution {
	public:
	int solve(vector<int>& a, vector<int>& b, vector<vector<int>>& c) {
		n=a.size();
		for(int i=0;i<n;i++)
		{
			adj[i].clear();
			vis[i]=false;
		}
		cc.clear();

		for(auto v:c)
		{
			if(v[0]<v[1]) swap(v[0],v[1]);
			adj[v[0]].push_back(v[1]);
			adj[v[1]].push_back(v[0]);
		}

		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			cc.push_back({});
			dfs(i);
		}

		int ans=0;
		for(auto vec:cc)
		{
			map <int,int> ma,mb;
			for(int i=0;i<vec.size();i++)
			{
				ma[a[vec[i]]]++;
				mb[b[vec[i]]]++;
			}

			for(auto p:ma)
				ans+=min(p.second,mb[p.first]);
		}
		return ans;
	}
};
