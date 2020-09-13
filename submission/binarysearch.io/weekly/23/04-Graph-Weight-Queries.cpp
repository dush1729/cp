
#include "solution.hpp"
using namespace std;

const int N=1e5+20;

int n,p[N],sz[N];


bool cmp(vector <int> &a,vector <int> &b)
{
	return a[2]<b[2];
}

void init() {for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;}

int root(int i) {return p[i]==i?i:p[i]=root(p[i]);}

bool cycle(int a,int b) {return root(a)==root(b);}

void join(int a,int b)
{
	a=root(a),b=root(b);
	if(sz[a]<sz[b]) swap(a,b);
	p[b]=p[a],sz[a]+=sz[b];
}

class Solution {
	public:
	int solve(vector<vector<int>>& edges, vector<vector<int>>& queries) {

		sort(edges.begin(),edges.end(),cmp);
		sort(queries.begin(),queries.end(),cmp);
		for(auto &v:edges) v[0]++,v[1]++;
		for(auto &v:queries) v[0]++,v[1]++;



		n=1;
		for(auto v:edges) n=max({n,v[0],v[1]});
		init();




		int ptr=0,ans=0;
		for(auto v:queries)
		{
			while(ptr<edges.size() and edges[ptr][2]<=v[2])
			{
				if(not cycle(edges[ptr][0],edges[ptr][1]))
					join(edges[ptr][0],edges[ptr][1]);
				ptr++;
			}

			if(cycle(v[0],v[1])) ans++;
		}
		return ans;
	}
};
